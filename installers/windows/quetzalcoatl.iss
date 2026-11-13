#ifndef ContentDir
  #error ContentDir must point to the staged content directory
#endif
#ifndef ManifestFile
  #error ManifestFile must point to samples-manifest.json
#endif
#ifndef InstallScript
  #error InstallScript must point to install-content.ps1
#endif
#ifndef PluginFile
  #error PluginFile must point to the built VST3 binary
#endif
#ifndef MergeScript
  #error MergeScript must point to merge-content.ps1
#endif
#ifndef OutputDir
  #error OutputDir must point to the installer output directory
#endif

[Setup]
AppId={{E90EF900-6594-4B44-B250-17C050B91102}
AppName=Quetzalcoatl
AppVersion=1.0.0
AppPublisher=modularsamples
DefaultDirName={commoncf64}\VST3
DisableDirPage=yes
DisableProgramGroupPage=yes
PrivilegesRequired=admin
ArchitecturesAllowed=x64compatible
ArchitecturesInstallIn64BitMode=x64compatible
OutputDir={#OutputDir}
OutputBaseFilename=Quetzalcoatl-1.0.0-Windows-unsigned
Compression=lzma2/fast
SolidCompression=yes
WizardStyle=modern

[Tasks]
Name: "samples"; Description: "Download and install the optional factory sample library (about 720 MB)"

[Dirs]
; Presets and favourites in the shared data folder must remain writable by
; ordinary users. The plugin binaries remain in the protected VST3 folder.
Name: "{commonappdata}\modularsamples\Quetzalcoatl"; Permissions: users-modify; Flags: uninsneveruninstall
; Original user must read the staging files, including when setup is elevated
; with another account. Keep them outside the user-writable data directory.
Name: "{code:GetStageDir}"; Permissions: users-readexec; Flags: deleteafterinstall

[Files]
Source: "{#PluginFile}"; DestDir: "{commoncf64}\VST3"; Flags: ignoreversion
Source: "{#ContentDir}\*"; DestDir: "{code:GetStageDir}\content"; Flags: recursesubdirs createallsubdirs deleteafterinstall
Source: "{#ManifestFile}"; DestDir: "{code:GetStageDir}"; DestName: "samples-manifest.json"; Flags: deleteafterinstall
Source: "{#MergeScript}"; DestDir: "{code:GetStageDir}"; DestName: "merge-content.ps1"; Flags: deleteafterinstall
Source: "{#InstallScript}"; DestDir: "{code:GetStageDir}"; DestName: "install-content.ps1"; Flags: deleteafterinstall

[Code]
function GetStageDir(Param: String): String;
begin
  Result := ExpandConstant('{commonappdata}\Quetzalcoatl-installer-') +
    ExtractFileName(ExpandConstant('{tmp}'));
end;

function PrepareToInstall(var NeedsRestart: Boolean): String;
begin
  Result := '';
  if DirExists(GetStageDir('')) then
    Result := 'Temporary installer staging directory already exists; please retry setup.';
end;

procedure CurStepChanged(CurStep: TSetupStep);
var ResultCode: Integer;
    Args, Stage: String;
begin
  if CurStep = ssPostInstall then begin
    Stage := GetStageDir('');
    Args := '-NoProfile -NonInteractive -ExecutionPolicy Bypass -File "' +
      Stage + '\install-content.ps1" -Content "' + Stage + '\content" -Destination "' +
      ExpandConstant('{commonappdata}\modularsamples\Quetzalcoatl') + '"';
    if WizardIsTaskSelected('samples') then
      Args := Args + ' -DownloadSamples';
    if not ExecAsOriginalUser(ExpandConstant('{sys}\WindowsPowerShell\v1.0\powershell.exe'),
        Args, '', SW_HIDE, ewWaitUntilTerminated, ResultCode) then
      RaiseException('Could not start the content installer.');
    if ResultCode <> 0 then
      RaiseException('The content installer failed with exit code ' + IntToStr(ResultCode) + '.');
    if not DelTree(Stage, True, True, True) then
      Log('Could not remove installer staging folder: ' + Stage);
  end;
end;
