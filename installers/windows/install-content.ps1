# Run as the original installing user, so Music resolves to their profile.
param(
    [Parameter(Mandatory = $true)][string]$Content,
    [Parameter(Mandatory = $true)][string]$Samples,
    [Parameter(Mandatory = $true)][string]$Destination,
    [string]$MusicFolder = ''
)
$ErrorActionPreference = 'Stop'
if (-not (Test-Path -LiteralPath $Content -PathType Container)) { throw 'Content is missing' }
if (-not (Test-Path -LiteralPath $Samples -PathType Container) -or
    -not (Get-ChildItem -LiteralPath $Samples -Filter '*.ch1' -Recurse -File | Select-Object -First 1)) {
    throw 'Sample library is missing'
}
if (-not $MusicFolder) {
    $MusicFolder = [Environment]::GetFolderPath([Environment+SpecialFolder]::MyMusic, [Environment+SpecialFolderOption]::DoNotVerify)
}
if (-not $MusicFolder -or -not [IO.Path]::IsPathRooted($MusicFolder)) { throw 'Cannot determine the original user Music directory' }
$sampleDestination = Join-Path $MusicFolder 'modularsamples\Quetzalcoatl\Samples'
$merge = Join-Path $PSScriptRoot 'merge-content.ps1'
& $merge -Source $Content -Destination $Destination
& $merge -Source $Samples -Destination $sampleDestination
# HISE reads an absolute UTF-8 path without shell/environment expansion.
[IO.File]::WriteAllText((Join-Path $Destination 'LinkWindows'), $sampleDestination, [Text.UTF8Encoding]::new($false))
Write-Host "Installed samples to $sampleDestination"
