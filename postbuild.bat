@echo off
set GameDir=C:\Program Files (x86)\Steam\steamapps\common\SleepingDogsDefinitiveEdition
echo F|xcopy /S /Q /Y /F "%1" "%GameDir%\plugins\VehPhysicsTweaker.asi"