#//github.com/IAmFatAndLazy
#Serial keyboard interpretor for Arduino

from time import sleep
import serial
import serial.tools.list_ports
import sys
import time
from pynput.keyboard import Key, Controller

keyboard = Controller()

#default values
port = "COM3"
baudrate = 9600
timeout = 1 

#THIS IF THE FUNCTION KEY, IE: FUNCTION KEY AND F1, F2, etc.
#key to use in pairing
function_key = Key.f20

#Change Key.KEY to change the key that will be emulated
keys = {
'K1':Key.f11,
'K2':Key.f2,
'K3':Key.f3,
'K4':Key.f4,
'K5':Key.f5,
'K6':Key.f6,
'K7':Key.f7,
'K8':Key.f8,
'K9':Key.f9,
'K10':Key.f10
}

#getting command line arguments
print('Starting micro-controller interpreter:')
if len(sys.argv)==1:
	#open serial connection with default settings
	print("\nNo arguments entered, using default connection settings\n")
elif len(sys.argv)==2:
	#open serial connection with custom port settings
	print("\nOpening connection to "+str(sys.argv[1])+" with default baudrate of "+str(baudrate)+"\n")
	port = str(sys.argv[1])
elif len(sys.argv)==3:
	#open serial connection with custom port and baudrate settings
	print("\nOpening connection to "+str(sys.argv[1])+" with a baudrate of "+str(sys.argv[2])+"\n")
	port = str(sys.argv[1])
	baudrate = sys.argv[2]


#trying to connect to device
try:	
	#get list of ports
	allPorts = [tuple(p) for p in list(serial.tools.list_ports.comports())]
	#if port is in list open the port
	if port in str(allPorts):
		ser = serial.Serial(port,baudrate,timeout=timeout)
		print("Connection established!\n")
	else:
		print("Device not found.")
		sys.exit(0)
except:
	print("Failed to connect! Make sure you've selected to correct port.\n")



while True:
	try:
	
		#read byte string and strip newline character
		rawData = ser.readline().strip();
		#convert byte string to ASCII string
		data = rawData.decode('ascii')
		#if data is not blank (AKA as long as theres data)
		if data != '':	
			#print which key pressed
			print('KeyPressed:' + str(data))
			
			#simulate key presses
			with keyboard.pressed(function_key):

				#simulate key press
				keyboard.press(keys.get(data))
				print("Emulated "+str(keys.get(data))+" key pressed")
				#simulate key release
				keyboard.release(keys.get(data))
				
	except:
		#check if device is still connected
		allPorts = [tuple(p) for p in list(serial.tools.list_ports.comports())]
		if port in str(allPorts):
			try:
				ser = serial.Serial(port,baudrate,timeout=timeout)
				print("Connection re-established!\n")
			except:
				print("Failed to re-connect to device!.\n")
		
		else :
			print("Device no longer connected. Awaiting 10 seconds before trying to re-connect")
			time.sleep(10)
			
		
		
				