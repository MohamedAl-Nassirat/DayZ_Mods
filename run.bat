@echo off
cls

set watch=DayZ Server

title %watch% Watchdog

cd "C:\Program Files (x86)\Steam\steamapps\common\DayZServer"

:watchdog
echo (%time%) %watch% started.
start "DayZ Server" /wait "DayZServer_x64.exe" -adminlog -netlog -freezecheck -showScriptErrors VerifySignatures=2; -profiles=ServerProfiles -config=serverDZ.cfg -port=2302 -dologs "-servermod=" "-mod=@CF;@VPPAdminTools;@test;" "-profiles=C:\Program Files (x86)\Steam\steamapps\common\DayZServer\profiles"
echo (%time%) %watch% closed or crashed, restarting.
goto watchdog
-profiles="C:\Program Files (x86)\Steam\steamapps\common\DayZServer\logs" -scrAllowFileWrite -dologs -adminlog