# Run as the original installing user, so Music resolves to their profile.
param(
    [Parameter(Mandatory = $true)][string]$Content,
    [Parameter(Mandatory = $true)][string]$Destination,
    [switch]$DownloadSamples,
    [string]$Samples = '',
    [string]$MusicFolder = ''
)
$ErrorActionPreference = 'Stop'
if (-not (Test-Path -LiteralPath $Content -PathType Container)) { throw 'Content is missing' }
$merge = Join-Path $PSScriptRoot 'merge-content.ps1'
& $merge -Source $Content -Destination $Destination
if (-not $DownloadSamples -and -not $Samples) { return }
if (-not $MusicFolder) {
    $MusicFolder = [Environment]::GetFolderPath([Environment+SpecialFolder]::MyMusic, [Environment+SpecialFolderOption]::DoNotVerify)
}
if (-not $MusicFolder -or -not [IO.Path]::IsPathRooted($MusicFolder)) { throw 'Cannot determine the original user Music directory' }
$sampleDestination = Join-Path $MusicFolder 'modularsamples\Quetzalcoatl\Samples'
$temp = $null
try {
    if ($DownloadSamples) {
        $temp = Join-Path ([IO.Path]::GetTempPath()) ('quetzal-samples-' + [guid]::NewGuid())
        New-Item -ItemType Directory -Path $temp | Out-Null
        $archive = Join-Path $temp 'Samples.zip'
        & curl.exe --fail --location --retry 2 --connect-timeout 30 --output $archive 'https://github.com/publicsamples/Quetzalcoatl/releases/download/1.0.0/Samples.zip'
        if ($LASTEXITCODE -ne 0) { throw "Sample download failed: $LASTEXITCODE" }
        $expected = '84ec2a7db78e30d0eac84dbf2488b8586d62b7380b6b051ecbec46ac5e040afc'
        if ((Get-FileHash -LiteralPath $archive -Algorithm SHA256).Hash -ine $expected) { throw 'Sample download checksum mismatch' }
        Expand-Archive -LiteralPath $archive -DestinationPath (Join-Path $temp 'extracted')
        $Samples = Join-Path $temp 'extracted/Samples'
        $manifest = Get-Content -Raw -LiteralPath (Join-Path $PSScriptRoot 'samples-manifest.json') | ConvertFrom-Json
        foreach ($entry in $manifest.PSObject.Properties) {
            $file = Join-Path $Samples $entry.Name
            if (-not (Test-Path -LiteralPath $file -PathType Leaf)) { throw "Sample missing: $($entry.Name)" }
            (Get-Item -LiteralPath $file).LastWriteTimeUtc = [DateTimeOffset]::FromUnixTimeSeconds([long]$entry.Value).UtcDateTime
        }
    }
    if (-not (Test-Path -LiteralPath $Samples -PathType Container) -or
        -not (Get-ChildItem -LiteralPath $Samples -Filter '*.ch1' -Recurse -File | Select-Object -First 1)) { throw 'Sample library is missing' }
    & $merge -Source $Samples -Destination $sampleDestination
    [IO.File]::WriteAllText((Join-Path $Destination 'LinkWindows'), $sampleDestination, [Text.UTF8Encoding]::new($false))
    Write-Host "Installed samples to $sampleDestination"
} finally {
    if ($temp -and (Test-Path -LiteralPath $temp)) { Remove-Item -LiteralPath $temp -Recurse -Force }
}
