import gspread
import serial
from oauth2client.service_account import ServiceAccountCredentials

arduino = serial.Serial('COM5', 9600, timeout=.1)

while True:
    data = arduino.readline()[:-2]  # the last bit gets rid of the new-line chars
    if data:
        print(data)


scope = ['https://spreadsheets.google.com/feeds',
         'https://www.googleapis.com/auth/drive']

credentials = ServiceAccountCredentials.from_json_keyfile_name('abejas-iot-key.json', scope)

gc = gspread.authorize(credentials)


wks = gc.open("abejas-iot").sheet1
wks.update_acell('B1''B2', data)
