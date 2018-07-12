import gspread
from oauth2client.service_account import ServiceAccountCredentials
import serial

scope = ['https://spreadsheets.google.com/feeds',
         'https://www.googleapis.com/auth/drive']

credentials = ServiceAccountCredentials.from_json_keyfile_name('abejas-iot-key.json', scope)

gc = gspread.authorize(credentials)

wks = gc.open("abejas-iot").sheet1

arduino = serial.Serial('/dev/ttyACM0', baudrate=9600, timeout=3.0)

a=1
while True:
	data = arduino.readline()
	wks.update_cell(a, 1, data)
	a=a+1
	
	


