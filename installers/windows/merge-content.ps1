# Merge extracted release content into the machine-wide application-data folder.
# Run from the installer after extracting the content to a private temporary folder.
param(
    [Parameter(Mandatory = $true)][string]$Source,
    [Parameter(Mandatory = $true)][string]$Destination
)
$ErrorActionPreference = 'Stop'
$sourcePath = (Resolve-Path -LiteralPath $Source).Path.TrimEnd('\')
if (-not (Test-Path -LiteralPath $sourcePath -PathType Container)) { throw 'Content folder not found' }
New-Item -ItemType Directory -Force -Path $Destination | Out-Null
Get-ChildItem -LiteralPath $sourcePath -Recurse -File | ForEach-Object {
    $file = $_
    $relative = $file.FullName.Substring($sourcePath.Length + 1)
    if ($relative -match '(^|\\)\.DS_Store$' -or $relative -match '^__MACOSX\\') { return }
    $target = Join-Path $Destination $relative
    if (Test-Path -LiteralPath $target) {
        if (-not (Test-Path -LiteralPath $target -PathType Leaf)) { throw "Not a file: $target" }
        if ($relative -ieq 'GeneralSettings.xml' -or $relative -ieq 'User Presets\db.json') { return }
        $existing = Get-Item -LiteralPath $target
        if ($file.LastWriteTimeUtc -le $existing.LastWriteTimeUtc) { return }
    }
    New-Item -ItemType Directory -Force -Path (Split-Path -Parent $target) | Out-Null
    Copy-Item -LiteralPath $file.FullName -Destination $target -Force
    (Get-Item -LiteralPath $target).LastWriteTimeUtc = $file.LastWriteTimeUtc
}
