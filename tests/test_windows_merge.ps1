$ErrorActionPreference = 'Stop'
$root = Join-Path ([IO.Path]::GetTempPath()) ('quetzal-merge-' + [guid]::NewGuid())
$src = Join-Path $root 'src'
$dst = Join-Path $root 'dst'
try {
    New-Item -ItemType Directory -Force (Join-Path $src 'User Presets'), (Join-Path $dst 'User Presets') | Out-Null
    Set-Content -LiteralPath (Join-Path $dst 'newer') -Value 'old' -NoNewline
    Set-Content -LiteralPath (Join-Path $src 'newer') -Value 'new' -NoNewline
    Set-Content -LiteralPath (Join-Path $dst 'equal') -Value 'kept' -NoNewline
    Set-Content -LiteralPath (Join-Path $src 'equal') -Value 'replaced' -NoNewline
    Set-Content -LiteralPath (Join-Path $dst 'user') -Value 'kept' -NoNewline
    Set-Content -LiteralPath (Join-Path $dst 'GeneralSettings.xml') -Value 'settings' -NoNewline
    Set-Content -LiteralPath (Join-Path $src 'GeneralSettings.xml') -Value 'factory' -NoNewline
    Set-Content -LiteralPath (Join-Path $dst 'User Presets/db.json') -Value 'favourites' -NoNewline
    Set-Content -LiteralPath (Join-Path $src 'User Presets/db.json') -Value 'factory' -NoNewline
    Set-Content -LiteralPath (Join-Path $src 'User Presets/new.preset') -Value 'add' -NoNewline
    $old = [DateTime]::SpecifyKind([DateTime]'2020-01-01', [DateTimeKind]::Utc)
    $new = [DateTime]::SpecifyKind([DateTime]'2024-01-01', [DateTimeKind]::Utc)
    foreach ($p in @((Join-Path $dst 'newer'), (Join-Path $dst 'equal'), (Join-Path $src 'equal'))) { (Get-Item $p).LastWriteTimeUtc = $old }
    foreach ($p in @((Join-Path $src 'newer'), (Join-Path $src 'GeneralSettings.xml'), (Join-Path $src 'User Presets/db.json'))) { (Get-Item $p).LastWriteTimeUtc = $new }
    & ./installers/windows/merge-content.ps1 -Source $src -Destination $dst
    foreach ($pair in @(@('newer','new'), @('equal','kept'), @('user','kept'), @('GeneralSettings.xml','settings'), @('User Presets/db.json','favourites'), @('User Presets/new.preset','add'))) {
        if ((Get-Content -Raw -LiteralPath (Join-Path $dst $pair[0])) -ne $pair[1]) { throw "Unexpected content: $($pair[0])" }
    }
    Write-Host 'Windows content merge checks passed'
} finally {
    if (Test-Path $root) { Remove-Item -Recurse -Force $root }
}
