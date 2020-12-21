import os

os.system ("ls /dev/tty.* > ports")
with open('ports', 'r') as file:ports = file.read().strip()
#print (ports)
#print len(ports)
#print ("Plug MEWT into a USB port...")
os.system ("osascript -e 'tell app \"System Events\" to display dialog  \"Plug MEWT into a USB port...\"'")
ports3 = ""
#print len(ports3)
print ("Installing MEWT, please plug MEWT into a USB port...")
while len(ports3) == 0: 
  os.system ("ls /dev/tty.* > ports2")
  with open('ports2', 'r') as file:ports2 = file.read().strip()
  #print (ports2)
  #print len(ports2)

  os.system ("diff ports ports2 > ports3")
  with open('ports3', 'r') as file:ports3 = file.read().strip()
  #print (ports3)
  #print len(ports3)
  if (len(ports3) > 0):
    break
os.system ("more ports3 | awk -F'[ ]' '{print $2}' > port_arduino")
with open('port_arduino', 'r') as file:port_arduino = file.read().strip()
print ('Your MEWT is on USB Serial Port: ' + port_arduino)
os.system ("rm ports")
os.system ("rm ports2")
os.system ("rm ports3")
#print ('MEWT configured, launching MEWT')
os.system ("osascript -e 'display notification \"MEWT configured, launching MEWT\"'")
os.system ("python mewt.py")
