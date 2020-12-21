import serial
import time
import csv
import os
from subprocess import Popen, PIPE

with open('port_arduino', 'r') as file:data = file.read().strip()
ser = serial.Serial(data)
ser.flushInput()
last_button_press = 2
time.sleep(2)
ser.write("101")
time.sleep(1)
ser.write("1")
os.system("clear")
print ("MEWT Ready")
while True:
  try:
    ser_bytes = ser.readline()
    decoded_bytes = str(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
#    print(decoded_bytes)
    with open("test_data.csv","a") as f:
      writer = csv.writer(f,delimiter=",")
      writer.writerow([time.time(),decoded_bytes])
    if decoded_bytes != last_button_press:
      if decoded_bytes == "1":
        os.system("clear")
        print("MEWTED")
        os.system("osascript ./mac_native_mewt.scpt")
      elif decoded_bytes == "0":
        os.system("clear")
        print("UNMEWTED")
        os.system("osascript ./mac_native_unmewt.scpt")
      last_button_press = decoded_bytes
#      def run_applescript(script, string_argument):
#        (stdout, stderr) = Popen(["osascript", script, "\""+string_argument+"\""], stdout=PIPE).communicate()
#        return stdout
#      ser.write(run_applescript("./applescript_return_mewt_state.scpt", "test string"))
      if decoded_bytes == "1":
        ser.write("0")
      elif decoded_bytes == "0":
        ser.write("1")
      ser.flush()
  except:
    print("Keyboard Interrupt")
    break
