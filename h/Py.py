import serial

ser = serial.Serial('/dev/ttyACMO/', 9600)

while True:
	read = ser.readline()
	print read
ser.close()
