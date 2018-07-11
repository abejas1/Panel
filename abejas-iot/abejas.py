import gspread
from oauth2client.service_account import ServiceAccountCredentials

scope = ['https://spreadsheets.google.com/feeds',
         'https://www.googleapis.com/auth/drive']

credentials = ServiceAccountCredentials.from_json_keyfile_name('abejas-iot-key.json', scope)

gc = gspread.authorize(credentials)

wks = gc.open("abejas-iot").sheet1
wks.update_acell('B1', 'Bingo!')
