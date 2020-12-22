import os

os.system ("cd $HOME/mewt")
os.system ("ls /dev/tty* > ports") 
ports3 = ""
print ("plug in now")
while len(ports3) == 0:
  os.system ("ls /dev/tty* > ports2")
  with open('ports2', 'r') as file:ports2 = file.read().strip()

  os.system ("diff ports ports2 > ports3")
  with open('ports3', 'r') as file:ports3 = file.read().strip()
  if (len(ports3) > 0):
    break
os.system ("more ports3 | awk -F'[ ]' '{print $2}' > port_arduino")
with open('port_arduino', 'r') as file:port_arduino = file.read().strip()
print ('Your MEWT is on USB Serial Port: ' + port_arduino)
os.system ("rm ports")
os.system ("rm ports2")
os.system ("rm ports3")
print ('MEWT configured, launching MEWT')
os.system ("python3 linux_mewt.py")
