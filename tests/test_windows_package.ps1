$ErrorActionPreference = 'Stop'
$root = Join-Path ([IO.Path]::GetTempPath()) ('quetzal-package-' + [guid]::NewGuid())
try {
    $content = Join-Path $root 'content'
    $output = Join-Path $root 'output'
    New-Item -ItemType Directory -Force -Path $content, $output | Out-Null
    Set-Content -LiteralPath (Join-Path $content 'AudioResources.dat') -Value 'audio' -NoNewline
    $manifest = Join-Path (Get-Location).Path 'installers/windows/samples-manifest.json'
    $install = Join-Path (Get-Location).Path 'installers/windows/install-content.ps1'
    $plugin = Join-Path $root 'Quetzalcoatl.vst3'
    Set-Content -LiteralPath $plugin -Value 'test plugin' -NoNewline
    $merge = Join-Path (Get-Location).Path 'installers/windows/merge-content.ps1'
    $iscc = 'C:/Program Files (x86)/Inno Setup 6/ISCC.exe'
    if (-not (Test-Path -LiteralPath $iscc)) { throw 'Inno Setup 6 not found' }
    & $iscc "/DContentDir=$content" "/DManifestFile=$manifest" "/DInstallScript=$install" "/DPluginFile=$plugin" "/DMergeScript=$merge" "/DOutputDir=$output" 'installers/windows/quetzalcoatl.iss'
    if ($LASTEXITCODE -ne 0) { throw "Inno Setup failed: $LASTEXITCODE" }
    if (-not (Test-Path -LiteralPath (Join-Path $output 'Quetzalcoatl-1.0.0-Windows-unsigned.exe'))) { throw 'Installer was not created' }
    Write-Host 'Windows installer compiled'
} finally {
    if (Test-Path -LiteralPath $root) { Remove-Item -LiteralPath $root -Recurse -Force }
}
