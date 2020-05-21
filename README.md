# Arduino-Serial-Hotkeys
Allows the use of older Arduinos to emulate keystrokes using an interpretation layer combined with AutoHotKey.
I created this solution because I was too lazy to just order a new Arduino nano for a macro keyboard project. 
Hopefully someone else can make use of this. As with all my projects, if you have any issues or questions feel free to reach out 
either by creating an issue on github or through my Discord IAmFatAndLazy#9850

# Use
Once everything is setup and configured (see below), simply running the ` RunInterpreter.bat ` file alongside your AutoHotKey script will get everything working. Keys emulated using pynput **WILL** be flagged as artificial keystrokes and may not be recognized during some games or applications use. I'd suggest adding your AutoHotKey script and the ` RunInterpreter.bat ` file to your Windows startup for most ease of use.

# Setup
### Arduino Wiring
- Decide how many keys will be connected to the Arduino
- Connect one side of your keys, buttons, etc. to your desired pins on the Arduino **NOTE: if you plan on creating a matrix to handle a large amount of keys, the system side code should handle it fine but you'll want to change the Arduino code pretty heavily**
- Connect the other side of your keys, buttons, etc. to GND

# Installation
Download or clone the repository somewhere you can access it.

### Arduino code
- Open the `KeyInterpretor.ino` file found in the `Arduino Code` folder
- Change the values of each button to correspond with the pin you've connected it to
- Remove or add as many buttons as needed from both the variables and the big ugly if section below (might fix that)
- Write the code to your Arduino

### Python
**This script requires Pynput and Pyserial to work. See the Dependencies section on how to acquire.**<br><br>
**I wrote this code with Python3 in mind; however it should run fine with Python2**
- Open the ` SerialRead.p ` file  found in the ` Python Script ` folder in your editor of choice
- change the ` function_key ` variable to the function key you would like associated with your hotkey. In the provided code it is set to F20, **IE: F20+a, F20+F2, F20+F3**
- Change the ` keys ` array to fit the number and keys you would like emulated.
- You may also change the ` default values ` to the COM port you are using however you can pass custom parameters to the script so it is not required.<br>**NOTE:** Pass parameters to the Python script in the following format `SerialRead.py [COM PORT] [BAUDRATE]`

- Save your changes

### Batch File
**The batch file will only work on Windows devices, if you are not running on a Windows device you will need to launch the python script directly with whatever parameters you'd like passed.**
- Open the ` RunInterpreter.bat ` file in the ` Python Script ` folder with your editor of choice.
- Modify the ` keyboardPort ` to the COM Port your Arduino is connected to.
- Modify the ` keyboardBaudRate ` to the Baud rate of your Arduino (This will be set correctly unless you've changed it in the Arduino code)
- Save your changes

<br>
Run The ` RunInterpreter.bat ` to start the script and confirm your key presses are being detected and emulated!

### AutoHotKey script
This will require most of your changes. I only wrote a quick file to allow you to test that you are correctly emulating keystrokes; however to do things you'll need to write or find your own scripts.
- Open the ` Example.ahk ` file in the ` Auto Hot Key example ` folder with your editor of choice.
change F20 and F2 to the keys you've associated with your buttons in the python script.
- Save your changes and run the AutoHotKey script.
- Pressing your button should display a message box.

# Dependencies
### Arduino
No required dependencies

### Python
- Pynput
- Pyserial
- To install these libraries you can use the following command <br>
` pip install pynput `<br>
` pip install pyserial `

## Batch
As stated, will only work in Windows enviornments but is very basic and can be redone in bash, etc.

## AutoHotKey
Can be downloaded from https://www.autohotkey.com/ <br>
You will need to make your AutoHotKey script on your own so dependencies will vary
