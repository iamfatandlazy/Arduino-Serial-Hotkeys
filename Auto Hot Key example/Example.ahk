;//github.com/IAmFatAndLazy

#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.


;F20 and F2 will display a message box as a test!
~F20 & F2::
	msgbox, Hotkey from your arduino!
	return