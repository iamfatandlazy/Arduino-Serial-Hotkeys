:: //github.com/IAmFatAndLazy

@echo off
SETLOCAL

:: Change these ports to what port your device is on. They will be passed to the python script as system arguments
SET keyboardPort="COM7"
SET keyboardBaudRate="9600"

echo Checking configuration

IF %keyboardPort%=="" (
	IF %keyboardBaudRate%=="" (
		echo Using default values
		echo ________________________
		GOTO loadDefaults
	)
) ELSE (
	echo Using custom values
	echo ________________________
	GOTO loadCustom
)

:loadDefaults
python SerialRead.py
pause
exit

:loadCustom
python SerialRead.py %keyboardPort% %keyboardBaudRate%
pause
exit
