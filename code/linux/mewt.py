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
string_to_send = "101"
bytes_to_send = str.encode(string_to_send)
ser.write(bytes_to_send)
time.sleep(1)
ser.write(str.encode("1"))
print ("MEWT Ready")
while True:
  try:
    ser_bytes = ser.readline()
    decoded_bytes = str(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
    with open("test_data.csv","a") as f:
      writer = csv.writer(f,delimiter=",")
      writer.writerow([time.time(),decoded_bytes])
    if decoded_bytes != last_button_press:
      if decoded_bytes == "1":
        os.system("clear")
        print("MEWTED")
        os.system("pacmd set-source-mute 3 1")
      elif decoded_bytes == "0":
        os.system("clear")
        print("UNMEWTED")
        os.system("pacmd set-source-mute 3 0")
      last_button_press = decoded_bytes
      if decoded_bytes == "1":
        ser.write(str.encode("0"))
      elif decoded_bytes == "0":
        ser.write(str.encode("1"))
      ser.flush()
  except:
    print("Keyboard Interrupt")
    break
