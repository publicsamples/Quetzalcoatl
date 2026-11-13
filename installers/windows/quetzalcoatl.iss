#ifndef ContentDir
  #error ContentDir must point to the staged content directory
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

[Dirs]
; Presets and favourites in the shared data folder must remain writable by
; ordinary users. The plugin binaries remain in the protected VST3 folder.
Name: "{commonappdata}\modularsamples\Quetzalcoatl"; Permissions: users-modify; Flags: uninsneveruninstall

[Files]
Source: "{#PluginFile}"; DestDir: "{commoncf64}\VST3"; Flags: ignoreversion
Source: "{#ContentDir}\*"; DestDir: "{tmp}\Quetzalcoatl-content"; Flags: recursesubdirs createallsubdirs deleteafterinstall
Source: "{#MergeScript}"; DestDir: "{tmp}"; DestName: "Quetzalcoatl-merge.ps1"; Flags: deleteafterinstall

[Code]
procedure CurStepChanged(CurStep: TSetupStep);
var ResultCode: Integer;
    Args: String;
begin
  if CurStep = ssPostInstall then begin
    Args := '-NoProfile -NonInteractive -ExecutionPolicy Bypass -File "' +
      ExpandConstant('{tmp}\Quetzalcoatl-merge.ps1') + '" -Source "' +
      ExpandConstant('{tmp}\Quetzalcoatl-content') + '" -Destination "' +
      ExpandConstant('{commonappdata}\modularsamples\Quetzalcoatl') + '"';
    if not Exec(ExpandConstant('{sys}\WindowsPowerShell\v1.0\powershell.exe'),
        Args, '', SW_HIDE, ewWaitUntilTerminated, ResultCode) then
      RaiseException('Could not start the content installer.');
    if ResultCode <> 0 then
      RaiseException('The content installer failed with exit code ' + IntToStr(ResultCode) + '.');
  end;
end;
