$ErrorActionPreference = 'Stop'
$root = Join-Path ([IO.Path]::GetTempPath()) ('quetzal-merge-' + [guid]::NewGuid())
$src = Join-Path $root 'src'
$dst = Join-Path $root 'dst'
try {
    New-Item -ItemType Directory -Force (Join-Path $src 'User Presets'), (Join-Path $dst 'User Presets') | Out-Null
    Set-Content -NoNewline (Join-Path $dst 'newer') 'old'
    Set-Content -NoNewline (Join-Path $src 'newer') 'new'
    Set-Content -NoNewline (Join-Path $dst 'equal') 'kept'
    Set-Content -NoNewline (Join-Path $src 'equal') 'replaced'
    Set-Content -NoNewline (Join-Path $dst 'user') 'kept'
    Set-Content -NoNewline (Join-Path $dst 'GeneralSettings.xml') 'settings'
    Set-Content -NoNewline (Join-Path $src 'GeneralSettings.xml') 'factory'
    Set-Content -NoNewline (Join-Path $dst 'User Presets/db.json') 'favourites'
    Set-Content -NoNewline (Join-Path $src 'User Presets/db.json') 'factory'
    Set-Content -NoNewline (Join-Path $src 'User Presets/new.preset') 'add'
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
