$ErrorActionPreference = 'Stop'
$root = Join-Path ([IO.Path]::GetTempPath()) ('quetzal-samples-' + [guid]::NewGuid())
try {
    $content = Join-Path $root 'content'
    $samples = Join-Path $root 'samples'
    $music = Join-Path $root 'My Music'
    $destination = Join-Path $root 'ProgramData/modularsamples/Quetzalcoatl'
    New-Item -ItemType Directory -Force -Path $content, $samples, $music | Out-Null
    Set-Content -LiteralPath (Join-Path $content 'AudioResources.dat') -Value 'audio' -NoNewline
    Set-Content -LiteralPath (Join-Path $samples 'test.ch1') -Value 'sample' -NoNewline
    New-Item -ItemType Directory -Force -Path $destination | Out-Null
    [IO.File]::WriteAllText((Join-Path $destination 'LinkWindows'), 'existing link')
    & ./installers/windows/install-content.ps1 -Content $content -Destination $destination
    if ([IO.File]::ReadAllText((Join-Path $destination 'LinkWindows')) -ne 'existing link') { throw 'Skipping samples changed the link' }
    & ./installers/windows/install-content.ps1 -Content $content -Samples $samples -Destination $destination -MusicFolder $music
    $sampleDir = Join-Path $music 'modularsamples/Quetzalcoatl/Samples'
    if ((Get-Content -Raw -LiteralPath (Join-Path $sampleDir 'test.ch1')) -ne 'sample') { throw 'Samples not installed' }
    if ([IO.File]::ReadAllText((Join-Path $destination 'LinkWindows')) -ne $sampleDir) { throw 'Sample link is incorrect' }
    Write-Host 'Windows sample installation checks passed'
} finally {
    if (Test-Path -LiteralPath $root) { Remove-Item -LiteralPath $root -Recurse -Force }
}
