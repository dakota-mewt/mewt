# Mewt
Mewt allows you to create a **hardware button to Mute and Unmute all system microphones with a single press for Windows, Mac and Linux**.  

Mewt works at the operating system (OS) level, so this **will mute/unmute all conferencing software** (Zoom, Google Meet, Teams, WebEx, Blue Jeans, GoToMeeting, Skype, Slack, Facebook, Discord, etc.)

Mewt will **continuously display the current Mute/Unmute state** so you can tell at a glance if your microphone is enabled without having to search for the onscreen icon. 

When Mewt detects that your microphone is transmitting audio, it will display a sound visualizer to help you **avoid embarassing hot-mic incidents via RGB LED light indicator**. _currently works in Windows, but not Mac or Linux_

![mewtdemo](/images/mewtdemo.gif)

Muted | Unmuted | Hot Mic
------------ | ------------- | -------------
![mewt](/images/mewt/red.jpg) | ![unmewt](/images/mewt/blue.jpg) | ![Hot Mic](/images/mewt/hotmic.gif)

# How Mewt works
<details>
 <summary>Click to expand</summary> 

Mewt is made up of 2 parts: 
   
1. Physical components
   1. A physical button to control mute state, with a built-in RGB LED to display mute state / hot-mic
   1. An Arduino microcontroller to interface with the button and the LED. This is also what will communicate with your computer
1. Code running on your computer to 
   1. Recognize button presses to toggle microphone mute/unmute
   1. Read microphone mute/unmute state and send information to the physical components to display status
   1. Read microphone volume levels and send information to the physical components to display hot-mic
![mewtdesign](/images/mewtdesign.png)

</details>

# How to build Mewt
<details>
 <summary>Click to expand</summary>


## Get physical components
<details>
 <summary>Click to expand</summary>

_Note: these are not referral links, I do not benefit from you clicking on these links.  I am not making an endorsement for Amazon or specific 3rd party merchants.  These are purely to help people get started_
### 1. Get a button (~$3 - $20)
* $18[![deluxemomentary](/images/deluxemomentary.png)](https://www.ebay.com/itm/333311892227)

  <details>
   <summary>Click to expand

  **Things to consider**
     </summary> 

  * **Size**: too small makes it hard to press, too big and it takes up desk space.  
  * **Depth**: shallower buttons are easier to mount
  * **LED**: you can find buttons without LED lights, with a single colored LED light, with two color LEDs, or even with RGB (Red/Green/Blue) LEDs.  Buttons with RGB LEDs allows Mewt to function fully, but they are also often bulkier, pricier and more difficult to wire.  
  * **State**: after you press it once, if it stays depressed (On state) and vice versa, it is called a "latching" button.  If after you press it, the button resets itself so that you can never tell if it's On or Off by visually looking at it, then it is called a "momentary" button.  Mewt works with either.
  * **Form factor**: Mewt can also work as a toggle switch instead of a button
  * **Common anode vs Common cathode**:  Mewt works with either.  This just affects how you physically connect it to the Arduino.
  * **Voltage**: 3V-6V are best as that is what Arduinos output.  I have had no issues with 12V.  I don't think Arduinos can drive 120/220V.
  * **Resistor**: Buttons with built-in LEDs typically have resistors already and do not need separate resistors
  * **SPST/SPDT/DPST/DPDT**: Super confusing, right?  Here's a [link that explains](https://spemco.com/blog/single-pole-triple-throw-triple-pole-single-throw-spst-dpdt-etc-how-to-tell-the-difference) it. TL;DR: get an SPST or SPDT.  avoid DPST/DPDT, they're overkill.

  **Other Examples**: 

  _ |Latch | Momentary | Switch 
  :-------------: | :-------------: | :-------------: | :-------------:
  Basic | ![basiclatching](/images/basiclatching.png)[$3](https://www.amazon.com/dp/B07WGNSRXR) | ![basicmomentary](/images/basicmomentary.png)[$3](https://www.amazon.com/dp/B07VSFLTMJ) | ![basictoggleswitch](/images/basictoggleswitch.png)[$3](https://www.amazon.com/dp/B07SXRKY6C/) 
  Deluxe | ![deluxelatching](/images/deluxelatching.png)[$8](https://www.amazon.com/gp/product/B07KQ3P2Y2) | ![deluxemomentary](/images/deluxemomentary.png)[$18](https://www.ebay.com/itm/333311892227) | ![deluxetoggleswitch](/images/deluxetoggleswitch.png)[$10](https://www.amazon.com/gp/product/B008DG7NWQ) 
  </details>

### 2. Get an Arduino microcontroller (~$10)
* $8[![cheappromicro](/images/cheappromicro.png)](https://www.amazon.com/dp/B07J2Q3ZD5/)
  <details>
   <summary>Click to expand

   **Things to consider**
     </summary>

  Any Arduino model (Pro Micro, Nano, Uno, etc) should work.  Pick the USB connector of your choice (Micro-USB, Mini-USB, UBS-C), Mewt is agnostic.  
  **Things to consider**:
  * **Size**: Pro Micro is the smallest, followed closely by the Nano. Unos are pretty big
  * **To solder or not**: if you don't want to solder, get an Uno or a Pro Micro/Nano with pre-soldered headers ![headers](/images/arduino-with-header.png) and a breadboard ![breadboard](/images/breadboard.png).  _Headers are the pins that stick out from the Arduino_

  **Examples**: 

  _ | Pro Micro | Nano | Uno 
  :------------: | :-------------: | :-------------: | :-------------:
  Size | Smallest ![promicro](/images/promicro.png) | Slightly larger ![nano](/images/nano.png)| Large ![uno](/images/uno.png)
  With Headers  | N/A |  [$6](https://www.amazon.com/dp/B082HGQ24C/) | [$11](https://www.amazon.com/dp/B016D5KOO)
  Without Headers  | [$8](https://www.amazon.com/dp/B07J2Q3ZD5) | [$13](https://www.amazon.com/dp/B07VX7MX27) | N/A
  </details>


### 3. Get wires, solder, soldering iron

### Don't want to solder?

  <details>
   <summary>If so, click here to expand</summary> 

### Basic Mewt
You may be interested in building a simplified version of Mewt because you don't want to solder, or because it is a good way to learn/experiment, or as a project for your kids. 

![mewtbasic](/images/mewtbasic.gif)

**Get an Arduino Starter Kit**: 
* $20[![arduinostarterkit](/images/arduinostarterkit.png)](https://www.amazon.com/dp/B01DGD2GAO/)

It will come with everything you need (Arduino, breadboard, wires, buttons, LEDs, resistors).  Plus you still have spare parts to make other projects when you're done!

 </details>
 

</details>

## Test physical components
<details>
 <summary>Click to expand</summary>

### 1. Plug in your Arduino and find its COM port
<details>
 <summary>Click to expand</summary>
 
* Windows
  <details>
   <summary>Click to expand</summary>
 
   1. Click Start 
   ![clickstart](/images/screenshots/windows/clickstart.png)
   1. Type in **_device manager_** to search and open 
   ![devicemanager](/images/screenshots/windows/devicemanager.png)
   1. Scroll down to **_ports_** and expand it.  _Note: you may not see a Ports listing until after the next step, don't panic._
   1. Now plug your Arduino into your computer's USB port.  Depending on your Arduino model, you may see some lights blink on your Arduino at this point.
   1. The **_Device Manager_** window may refresh at this point.  scroll down to **_ports_**, and expand it (again).
   1. You should see a listing for **_Arduino [specific model] (COMx)_** where **_x_** is usually a number from 3 - 15 
   ![ports](/images/screenshots/windows/ports.png)
   1. Jot down the COMx serial port somewhere, we'll need to reference it later
   * _If you do not see your Arduino here, or if you see a question mark icon, we will need to [Troubleshoot](#Troubleshooting)_
   </details>

* Mac
  <details>
   <summary>Click to expand</summary>
   
   1. Click **_Finder->Applications->Utilities->Terminal_** 
   ![terminal](/images/screenshots/mac/terminal.png)
   1. In the Terminal window, type in **_ls /dev/tty.*_** and hit enter. Make a mental note of the results.  
   ![portsbeforearduino](/images/screenshots/mac/portsbeforearduino.png)
   1. Now plug your Arduino into your computer's USB port.  Depending on your Arduino model, you may see some lights blink on your Arduino at this point.
   1. In the Terminal window, type in **_ls /dev/tty.*_** and hit enter (again). 
   ![portsafterarduino](/images/screenshots/mac/portsafterarduino.png)
   1. Jot down the new entry **_/dev/tty.XXXXXXXX_** serial port somewhere, we'll need to reference it later
   </details>
 

* Linux
  <details>
   <summary>Click to expand</summary>
   
   1. In a Terminal window, type in **_ls /dev/tty.*_** and hit enter. Make a mental note of the results.  
   ![portsbeforearduino](/images/screenshots/mac/portsbeforearduino.png)
   1. Now plug your Arduino into your computer's USB port.  Depending on your Arduino model, you may see some lights blink on your Arduino at this point.
   1. In the Terminal window, type in **_ls /dev/tty.*_** and hit enter (again). 
   ![portsafterarduino](/images/screenshots/mac/portsafterarduino.png)
   1. Jot down the new entry **_/dev/tty.XXXXXXXX_** serial port somewhere, we'll need to reference it later
   </details>
</details>

### 2. Download and install the Arduino IDE to test your Arduino
<details>
 <summary>Click to expand</summary>

1. Go to [The Arduino Download Page](https://www.arduino.cc/en/software) to download the latest IDE for your OS
1. Install and launch the IDE
1. Select **_File->New_** and delete everything in the new window that opens up
1. Select **_Tools->Board_** and choose your Arduino model.  _for Pro Micros, choose Arduino Leonardo_ 
![boards](/images/screenshots/arduino/boards.png)
1. Select **_Tools->Ports_** and choose the same serial port that you jotted down earlier 
![portselection](/images/screenshots/arduino/portselection.png)
1. In the editor window paste in this code borrowed from **Abdullah Al Mamun** from [Instructables.com](https://www.instructables.com/Arduino-Function-Serialread-And-SerialreadString/) 
 ```c
 String a;
 void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
 }

 void loop() {
  while(Serial.available()) {
   a= Serial.readString();// read the incoming data as string
   Serial.println(a);
  }
 }
```

1. Select **_Sketch->Verify/Compile_**.  You can click **_Save_** when it prompts you to save the sketch folder.  
![verifycompile](/images/screenshots/arduino/verifycompile.png)
1. You should see a green **Done Compiling** status at the bottom of your Arduino window 
![donecompiling](/images/screenshots/arduino/donecompiling.png)
1. Select **_Sketch->Upload_**.
![upload](/images/screenshots/arduino/upload.png)
1. You should see the status change to **Uploading**, the lights on the Arduino should blink, followed by a green **Done Uploading** status at the bottom of your Arduino window. 
![doneuploading](/images/screenshots/arduino/doneuploading.png)
1. If you get an error while uploading, some Arduino models require you to select your Bootloader.  To do that, select **_Tools->Processor->(Old Bootloader)_** and try uploading again.  
![processorbootloader](/images/screenshots/arduino/processorbootloader.png)
1. Select **_Tools->Serial Monitor_** 
![serialmonitor](/images/screenshots/arduino/serialmonitor.png)
1. Make sure the 2 selections on the lower right hand of the screen are: **Both NL & CR** and **9600 baud** 
![serialmonitorparameter](/images/screenshots/arduino/serialmonitorparameter.png)
1. In the text box, type in **_Hello World_** and click **_Send_**
1. If all goes well, you should see the same words show up below the text box next to a timestamp 
![helloworld](/images/screenshots/arduino/helloworld.png)
1. **Congratulations** if this is your first Arduino program!  Go get a gummi bear and shove it in your face!
 <details>
  <summary>
   
   _Curious as to what the program did?_
   </summary>
  
  It created a variable (**a**) to be a placeholder.  It then set speed at which the Arduino communicates with the computer over the Serial port (interesting tidbit, USB stands for _Universal **Serial** Bus_) to 9600 bauds.  Remember that is also the speed that we are using to monitor the iteractions.  
  
  After that, it runs an infinite loop that checks the Serial port for data.  If there's no data, it does nothing.  But since it's an infinite loop, it will immediately check the Serial port for data again.  This happens over and over again until finally you type in "Hello World" and hit Send.  That sends the data from your computer over the Serial port to the Arduino.  The check detects data when this happens.  It will then use the variable (**a**) to temporarily hold on to that data.  Lastly, it will dump that data back onto the Serial port for the computer to display.
  
  This is why everything you type in the text box will show up in the output window after a small delay.
 </details>
</details>



### 3. Test your button 
<details>
 <summary>Click to expand</summary>

* **SPST/SPDT/DPST/DPDT**: Here's a [link that explains](https://spemco.com/blog/single-pole-triple-throw-triple-pole-single-throw-spst-dpdt-etc-how-to-tell-the-difference) it.

**If your button is a SPST**
   <details>
   <summary>Click to expand</summary>
   
   Then, it should have 2 switch terminals.  
   * A Common (sometimes labeled **C**)
   * A Normally Open (sometimes labeled **NO**)
   
   </details>

**If your button is a SPDT**
   <details>
   <summary>Click to expand</summary>
   
   Then, it should have 3 switch terminals.  
   ![spdtschematics](/images/spdtschematics.png)
   * A Common (sometimes labeled **C**)
   * A Normally Open (sometimes labeled **NO**)
   * A Normally Closed (sometimes labeled **NC**)
   
   </details>
   


* Connect the button **NO** terminal to **D2** on your Arduino
* Connect the button **C** terminal to **GND** on your Arduino

_Consider testing with jumper cables and a breadboard rather than directly soldering.  It is easier to identify faulty components or make changes this way._
  ![buttontestwiring](/images/buttontestwiring.png)
* in the editor window paste in [this code](/code/arduino/tests/mewt-button-test.ino) 
  
 <details>
  <summary>
   
   _See the code_
   </summary>

   ```c
 const int mewtButton = 2;     
      int mewtState = 0;
      byte inByte;     
      int inInt;

 void setup() {
   Serial.begin(9600);
   Serial.setTimeout(50);
   // initialize digital pin LED_BUILTIN as an output.
   pinMode(LED_BUILTIN, OUTPUT);
   pinMode(mewtButton, INPUT_PULLUP);   
 }

 // the loop function runs over and over again forever
 void loop() {    
   mewtState = digitalRead(mewtButton);

   if (mewtState == LOW) {
     digitalWrite(LED_BUILTIN, HIGH);  
     Serial.println("pressed");      
     delay(500);
   }
   if (mewtState == HIGH) {
     digitalWrite(LED_BUILTIN, LOW);  
     Serial.println("released");      
     delay(500);
   }
   delay(500);
 }
   ```
 </details>   

1. Select **_Sketch->Verify/Compile_**.  You can click **_Save_** when it prompts you to save the sketch folder.  
![verifycompile](/images/screenshots/arduino/verifycompile.png)
1. You should see a green **Done Compiling** status at the bottom of your Arduino window 
![donecompiling](/images/screenshots/arduino/donecompiling.png)
1. Select **_Sketch->Upload_**.  
![upload](/images/screenshots/arduino/upload.png)
1. You should see the status change to **Uploading**, the lights on the Arduino should blink, followed by a green **Done Uploading** status at the bottom of your Arduino window. 
![doneuploading](/images/screenshots/arduino/doneuploading.png)
1. If you get an error while uploading, some Arduino models require you to select your Bootloader.  To do that, select **_Tools->Processor->(Old Bootloader)_** and try uploading again.  
![processorbootloader](/images/screenshots/arduino/processorbootloader.png)
1. Select **_Tools->Serial Monitor_** 
![serialmonitor](/images/screenshots/arduino/serialmonitor.png)
1. Make sure the 2 selections on the lower right hand of the screen are: **Both NL & CR** and **9600 baud** 
![serialmonitorparameter](/images/screenshots/arduino/serialmonitorparameter.png)
1. If all goes well, you should see the word **pressed** in the output window every time you press the button.  It should display **released** when you let go of the button.
![buttontest](/images/screenshots/arduino/buttontest.png)
1. If you get the opposite result of what you are looking for (output says **pressed** when you release the button and it says **released** when you press the button), simply swap the wires connecting to the button terminals
1. **Congratulations** if this is your first time connecting a piece of physical hardware to your code!  Go get another gummi bear and shove it in your face! 

 <details>
  <summary>
   
   _Curious as to what the program did?_
   </summary>
It sets a variable (**mewtButton**) to the Arduino #2 pin, and creates a variable (**mewtState**).  

It sets the Serial speed to be 9600, and a timeout of 50 (milliseconds).  The default timeout is 1 second, so a 50 millisecond time will allow faster responses from the Arduino.

We also initialize **LED_BUILTIN** (Arduino's built-in LED) and the MewtButton.  **INPUT_PULLUP** uses Arduino's built-in resistor so you can avoid having to physically wire in a resistor to make the button work.

Inside the infinite loop, we read the current state from **mewtButton**, which is reading from Arduino's #2 pin, and puts it into **mewtState** variable.  

Then we check the value of the state.  If it is **LOW**, then that means that the button has been pressed.  We then output that state by turning on **LED_BUILTIN** and also write **pressed** on the serial port to be displayed by the computer.  That will happen as long as the button is pressed.

If we release the button, then **mewtState** would be **HIGH**.  We then output that state by turning off **LED_BUILTIN** and also write **released** on the serial port to be displayed by the computer.  That will happen as long as the button is pressed.
 </details>

</details>

### 4. Test your LED 
<details>
 <summary>Click to expand</summary>

* **Common Cathode vs Common Anode**: Here's a [link that explains](https://forum.arduino.cc/index.php?topic=22413.0) it.

**If LED is Common Cathode**
   <details>
   <summary>Click to expand</summary>
      
   * A Common (sometimes labeled **C** or **-**) - you will connect this to **GND** on your Arduino
   * A Terminal for every color LED in your light - You will start by identifying the terminal for the red LED and connecting it to the **D4** pins on your Arduino
   ![ledtestwiring-commoncathode](/images/ledtestwiring-commoncathode.png)

* in the editor window paste in [this code](/code/arduino/tests/mewt-ledcommoncathode-test.ino) 
  
 <details>
  <summary>
   
   _See the code_
   </summary>

   ```c
   const int led0 = 0;     
   const int led1 = 1;     
   const int led3 = 3;     
   const int led4 = 4;     
   const int led5 = 5;     
   const int led6 = 6;     
   const int led7 = 7;     
   const int led8 = 8;     
   const int led9 = 9;     
   const int led10 = 10;     
   const int led11 = 11;     
   const int led12 = 12; 
   const int led13 = 13; 

   const int mewtButton = 2;     
         int mewtState = 0;
         byte inByte;     
         int inInt;

   void setup() {
     Serial.begin(9600);
     Serial.setTimeout(50);
     // initialize digital pin LED_BUILTIN as an output.
     pinMode(LED_BUILTIN, OUTPUT);
     pinMode(led0, OUTPUT);
     pinMode(led1, OUTPUT);
     pinMode(led3, OUTPUT);
     pinMode(led4, OUTPUT);
     pinMode(led5, OUTPUT);
     pinMode(led6, OUTPUT);
     pinMode(led7, OUTPUT);
     pinMode(led8, OUTPUT);
     pinMode(led9, OUTPUT);
     pinMode(led10, OUTPUT);
     pinMode(led11, OUTPUT);
     pinMode(led12, OUTPUT);
     pinMode(led13, OUTPUT);
     pinMode(mewtButton, INPUT_PULLUP);   
    }

   // the loop function runs over and over again forever
   void loop() {    
     digitalWrite(led0, HIGH);
     digitalWrite(led1, HIGH);
     digitalWrite(led3, HIGH);
     digitalWrite(led4, HIGH);
     digitalWrite(led5, HIGH);
     digitalWrite(led6, HIGH);
     digitalWrite(led7, HIGH);
     digitalWrite(led9, HIGH);
     digitalWrite(led10, HIGH);
     digitalWrite(led11, HIGH);
     digitalWrite(led12, HIGH);
     digitalWrite(led13, HIGH);
     mewtState = digitalRead(mewtButton);

     if (mewtState == LOW) {
       digitalWrite(LED_BUILTIN, HIGH);  
       Serial.println("pressed");      
       delay(50);
     }
     if (mewtState == HIGH) {
       digitalWrite(LED_BUILTIN, LOW);  
       Serial.println("released");      
       delay(50);
     }
   }
   ```
 </details>   
  </details>


**If LED is Common Anode**
   <details>
   <summary>Click to expand</summary>
   
   * A Common (sometimes labeled **C** or **+**) - you will connect this to **5V** on your Arduino
   * A Terminal for every color LED in your light - You will start by identifying the terminal for the red LED and connecting it to the **D4** pins on your Arduino
   ![ledtestwiring-commonannode](/images/ledtestwiring-commonanode.png)
   
* in the editor window paste in [this code](/code/arduino/tests/mewt-ledcommonanode-test.ino) 
  
 <details>
  <summary>
   
   _See the code_
   </summary>

   ```c
   const int led0 = 0;     
   const int led1 = 1;     
   const int led3 = 3;     
   const int led4 = 4;     
   const int led5 = 5;     
   const int led6 = 6;     
   const int led7 = 7;     
   const int led8 = 8;     
   const int led9 = 9;     
   const int led10 = 10;     
   const int led11 = 11;     
   const int led12 = 12; 
   const int led13 = 13; 

   const int mewtButton = 2;     
         int mewtState = 0;
         byte inByte;     
         int inInt;

   void setup() {
     Serial.begin(9600);
     Serial.setTimeout(50);
     // initialize digital pin LED_BUILTIN as an output.
     pinMode(LED_BUILTIN, OUTPUT);
     pinMode(led0, OUTPUT);
     pinMode(led1, OUTPUT);
     pinMode(led3, OUTPUT);
     pinMode(led4, OUTPUT);
     pinMode(led5, OUTPUT);
     pinMode(led6, OUTPUT);
     pinMode(led7, OUTPUT);
     pinMode(led8, OUTPUT);
     pinMode(led9, OUTPUT);
     pinMode(led10, OUTPUT);
     pinMode(led11, OUTPUT);
     pinMode(led12, OUTPUT);
     pinMode(led13, OUTPUT);
     pinMode(mewtButton, INPUT_PULLUP);   
    }

   // the loop function runs over and over again forever
   void loop() {    
     digitalWrite(led0, LOW);
     digitalWrite(led1, LOW);
     digitalWrite(led3, LOW);
     digitalWrite(led4, LOW);
     digitalWrite(led5, LOW);
     digitalWrite(led6, LOW);
     digitalWrite(led7, LOW);
     digitalWrite(led9, LOW);
     digitalWrite(led10, LOW);
     digitalWrite(led11, LOW);
     digitalWrite(led12, LOW);
     digitalWrite(led13, LOW);
     mewtState = digitalRead(mewtButton);

     if (mewtState == LOW) {
       digitalWrite(LED_BUILTIN, HIGH);  
       Serial.println("pressed");      
       delay(50);
     }
     if (mewtState == HIGH) {
       digitalWrite(LED_BUILTIN, LOW);  
       Serial.println("released");      
       delay(50);
     }
   }
   ```

   </details>

1. Select **_Sketch->Verify/Compile_**.  You can click **_Save_** when it prompts you to save the sketch folder.  
![verifycompile](/images/screenshots/arduino/verifycompile.png)
1. You should see a green **Done Compiling** status at the bottom of your Arduino window 
![donecompiling](/images/screenshots/arduino/donecompiling.png)
1. Select **_Sketch->Upload_**.
![upload](/images/screenshots/arduino/upload.png)
1. You should see the status change to **Uploading**, the lights on the Arduino should blink, followed by a green **Done Uploading** status at the bottom of your Arduino window. 
![doneuploading](/images/screenshots/arduino/doneuploading.png)
1. If all goes well, your LED will have lit up.
1. **Congratulations** you're a pro at this point!  Go get a third gummi bear!
1. Disconnect the **red LED** from **D4** and connect the **blue LED** to **D7**
1. Disconnect the **blue LED** and from **D7** connect the **green LED** to **D9**
1. **Congratulations** you have successfully tested all the components you need to make a fully functional Mewt!  Go get a gummi worm this time!

  </details>

**If you have an LED separate from your button (i.e. if you are building a Mewt Basic)**
   <details>
   <summary>Click to expand</summary>
     You will also need to add an inline resistor with every color terminal.
   Follow the above directions, but use this wiring instead:

**Common cathode**
   <details>
   <summary>Click to expand</summary>


   ![ledtestwiring-commonanode-resistor](/images/ledtestwiring-commoncathode-resistor.png)
   </details>
   
**Common Anode**
   <details>
   <summary>Click to expand</summary>
 
   ![ledtestwiring-commonanode-resistor](/images/ledtestwiring-commonanode-resistor.png)
   </details>
   
   </details>

</details>
</details>

## Assemble your Mewt 
<details>
 <summary>Click to expand</summary>

Connect your button/LED to your Arduino using the wiring applicable to your components

* Button terminal -> D2
* Button common -> GND
* LED red -> D4
* LED blue -> D7
* LED green -> D9
* LED common (anode) -> 5V
* LED common (cathode) -> GND

  _ | Common Cathode LED | Common Anode LED 
  :------------: | :-------------: | :-------------: 
  Deluxe (no additional resistors)| ![mewtwiring-commoncathode](/images/mewtwiring-commoncathode.png) | ![mewtwiring-commonanode](/images/mewtwiring-commonanode.png) 
  Basic (with resistors)  | ![mewtbasicwiring-commoncathode](/images/mewtbasicwiring-commoncathode.png) | ![mewtbasicwiring-commonanode](/images/mewtbasicwiring-commonanode.png) 
  
</details>

## Test your assembled Mewt 
<details>
 <summary>Click to expand</summary>
 
 ### PC
  _ | Common Cathode LED | Common Anode LED 
  :------------: | :-------------: | :-------------: 
  Momentary Button| [pc_momentary_common_cathode.ino](/code/arduino/pc_momentary_common_cathode.ino) | [pc_momentary_common_anode.ino](/code/arduino/pc_momentary_common_anode.ino) 
  Latching Button  | [pc_latch_rgb_common_cathode.ino](/code/arduino/pc_latch_rgb_common_cathode.ino) | [pc_latch_rgb_common_anode.ino](/code/arduino/pc_latch_rgb_common_anode.ino) 

 ### Mac and Linux
  _ | Common Cathode LED | Common Anode LED 
  :------------: | :-------------: | :-------------: 
  Momentary Button| [maclinux_momentary_common_cathode.ino](/code/arduino/maclinux_momentary_common_cathode.ino) | [maclinux_momentary_common_anode.ino](/code/arduino/maclinux_momentary_common_anode.ino) 
  Latching Button  | [maclinux_latch_rgb_common_cathode.ino](/code/arduino/maclinux_latch_rgb_common_cathode.ino) | [maclinux_latch_rgb_common_anode.ino](/code/arduino/maclinux_latch_rgb_common_anode.ino) 


<details>
 <summary>
  
   _Curious as to how these programs differ?_
   </summary>

* A **Common Cathode** LED shares a connection to Arduino's GND (-).  Arduino sets the state based on changing the voltage applied to the pin.  When you want to turn on an LED light, the code instructs Arduino to send a value of **HIGH**

* A **Common Anode** LED shares a connection to Arduino's 5V (+).  When you want to turn on an LED light, the code instructs Arduino to send a value of **LOW**

* A **Latching Button** stays locked to an on state or an off state depending on if you've pressed or released the button.  Arduino can simply read the current state to figure out if you intend Mewt to be enabled or not.

* A **Momentary Button** resets itself when you release the button.  Because of this lack of memory (or state), Arduino cannot rely on the status of the button to tell if Mewt should be enabled or not.  Instead, Arduino needs to keep track of the state inside the code with the use of a variable.

* The **PC Mewt** streams back the microphone mute/unmute state and transmitted volume (if applicable).  Therefore, Mewt can rely on a continuous state signal to decide which color to display.

* The **Mac / Linux Mewt** currently cannot stream back mute/unmute state and transmitted volume.  Mewt relies on knowledge of the mute/unmute state of the microphone at the time of button press to determine which color to display.  
</details>

1. Load the program applicable to your components into your Arduino IDE editor 
1. Select **_Sketch->Verify/Compile_**.  You can click **_Save_** when it prompts you to save the sketch folder.  
![verifycompile](/images/screenshots/arduino/verifycompile.png)
1. You should see a green **Done Compiling** status at the bottom of your Arduino window 
![donecompiling](/images/screenshots/arduino/donecompiling.png)
1. Select **_Sketch->Upload_**.
![upload](/images/screenshots/arduino/upload.png)
1. You should see the status change to **Uploading**, the lights on the Arduino should blink, followed by a green **Done Uploading** status at the bottom of your Arduino window. 
![doneuploading](/images/screenshots/arduino/doneuploading.png)
1. Select **_Tools->Serial Monitor_** 
![serialmonitor](/images/screenshots/arduino/serialmonitor.png)
1. Make sure the 2 selections on the lower right hand of the screen are: **Both NL & CR** and **9600 baud** 
![serialmonitorparameter](/images/screenshots/arduino/serialmonitorparameter.png)
1. If all goes well you should have the below reults
* when you press the button you should see the **Green LED** come on and the Arduino IDE window output should display either **1** or **0**.  Every time you press the button again, the value you see will toggle back and forth

![testmewtbuttonpress](/images/mewt/testmewtbuttonpress.gif)

  Type this into Arduino text box | This should light up
  :------------: | :-------------: 
  **0** | Red ![red](/images/mewt/red.jpg) 
  **1**  | Blue ![blue](/images/mewt/blue.jpg) 
  **2**  | Green ![green](/images/mewt/green.jpg) 
  **3**  | Purple ![purple](/images/mewt/purple.jpg) 
  **4**  | Yellow ![yellow](/images/mewt/yellow.jpg) 
  **5**  | White ![white](/images/mewt/white.jpg) 
  **101**  | Flash Green 3x ![greenblink3x](/images/mewt/greenblink3x.gif)
  
* **Congratulations** you have a fully functional Mewt!  Upgrade your gummi worm to a sour gummi worm!
</details>

## Connect your computer to your Mewt
<details>
 <summary>Click to expand</summary>
 
* Windows
  <details>
   <summary>Click to expand</summary>
   
   1. Download [mewt.exe](/code/windows/mewt.exe)   
   _your browser may give you a warning when you try to download.  Select **Keep** to continue downloading._
   ![keepanyway](/images/screenshots/windows/keepanyway.png)
   1. **IMPORTANT** please **UNPLUG** Mewt from your computer's USB before continuing.
   1. Find where you downloaded **mewt.exe** and run the file.
   1. Windows Defender / User Access Control may ask several times if you want to continue, follow screenshots to continue.
   ![windowsdefender](/images/screenshots/windows/windowsdefender.png)![runanyway](/images/screenshots/windows/runanyway.png)![unknownpublisher](/images/screenshots/windows/unknownpublisher.png)
   1. You will then see Mewt install itself
   ![installingmewt](/images/screenshots/windows/installingmewt.png)
   1. You will see a prompt to plug Mewt into a USB port
   ![pluginmewt](/images/screenshots/windows/pluginmewt.png)
   1. When you plug in your Mewt, the prompt will disappear.  Your Mewt may flash a white light briefly.  After a short delay, Mewt will light up with a steady Blue or Red light depending on whether your microphone is currently Unmuted or currently Muted.  _Based on your system/Arduino setup, it may take 15-20 seconds for the steady light to come on._
   ![mewtfirsttime](/images/mewtfirsttime.gif)
   1. The very first time you use Mewt, you will need to press the button twice in order to activate it (sorry, it's a bug, still a work-in-progress). After it has been activated, every single button press will turn every microphone in your system from Unmuted to Muted, and vice versa.  Below are what the colors represent:

   Color | Represents
  :------------: | :-------------: 
  **0** | Muted ![red](/images/mewt/red.jpg) 
  **1**  | Unmuted, but not transmitting ![blue](/images/mewt/blue.jpg) 
  **2**  | Button pressed ![green](/images/mewt/green.jpg) 
  **3**  | Hot-mic display ![purple](/images/mewt/purple.jpg) 
  **4**  | Hot-mic display  ![yellow](/images/mewt/yellow.jpg) 
  **5**  | Hot-mic display  ![white](/images/mewt/white.jpg) 
  **101**  | Microphone devices have changed ![greenblink3x](/images/mewt/greenblink3x.gif)
   * To test out Mewt, go to [online-voice-recorder.com](https://online-voice-recorder.com/), and click on the red button to record.  You should see it react to any sounds your microphone picks up.  
   ![onlinevoicerecorder](/images/onlinevoicerecorder.gif)  
   ![mewtdemo](/images/mewtdemo.gif)
   
   <details>
     <summary>
  
     _Curious as to what the installation program did? Did the installation not work?  Click here to expand_
     </summary>
     
   1. **mewt.exe** is a self-extracting version of **mewt.zip**.  
   1. Download **[mewt.zip](/code/windows/mewt.zip)** to your computer
   1. Navigate to where you saved **mewt.zip**, right click on it and select _**Extract All**_
   ![extractall](/images/screenshots/windows/extractall.png)
   1. In the next window, type in _**c:\mewt**_ then _**Extract**_
   ![extracttocmewt](/images/screenshots/windows/extracttocmewt.png)
   1. **IMPORTANT** please **UNPLUG** Mewt from your computer's USB before continuing.
   1. In _**File Explorer**_ navigate to **c:\mewt**, right click on **setup_mewt.bat** (its icon has gears in it), then select _**Open**_
   ![setup_mewt.bat](/images/screenshots/windows/setup_mewt.bat.png)
   1. You will see a prompt to plug Mewt into a USB port
   ![pluginmewt](/images/screenshots/windows/pluginmewt.png)
   1. When you plug in your Mewt, the prompt will disappear.  Your Mewt may flash a white light briefly.  After a short delay, Mewt will light up with a steady Blue or Red light depending on whether your microphone is currently Unmuted or currently Muted.  _Based on your system/Arduino setup, it may take 15-20 seconds for the steady light to come on._
   ![mewtfirsttime](/images/mewtfirsttime.gif)
   1. The very first time you use Mewt, you will need to press the button twice in order to activate it (sorry, it's a bug, still a work-in-progress). After it has been activated, every single button press will turn every microphone in your system from Unmuted to Muted, and vice versa.
   
   
   
   </details>  

   
* Mac
  <details>
   <summary>Click to expand</summary>
 
   1. Download [mewt.zip](/code/mac/mewt.zip)   
   _your browser may give you a warning when you try to download.  Select **Keep** to continue downloading._
   ![keepanyway](/images/screenshots/windows/keepanyway.png)
   1. **IMPORTANT** please **UNPLUG** Mewt from your computer's USB before continuing.
   1. Navigate to where you saved **mewt.zip** from ***Finder->Downloads***, right click on it and select _**Open With->Archive Utility**_
   ![extractall](/images/screenshots/mac/archiveutility.png)
   1. Open ***Terminal*** from ***Finder->Applications->Utilities->Terminal***
   1. In the Terminal console, navigate to where you unzipped **mewt.zip** _typically this is **cd $HOME/Downloads/mewt**_
   1. Type in ***python mac_install_mewt.py***, wait for the prompt to plug in your Mewt
   ![macinstall](/images/screenshots/mac/macinstall.png)
   1. When you plug in your Mewt, the prompt will disappear.  Your Mewt may flash a white light briefly.  After a short delay, Mewt will light up with a steady Blue.  _Based on your system/Arduino setup, it may take 15-20 seconds for the steady light to come on._
   ![mewtready](/images/screenshots/mac/mewtready.png)
   </details>

* Linux
  <details>
   <summary>Click to expand</summary>
   
   1. Download [mewt.zip](/code/linux/mewt.zip)   
   1. **IMPORTANT** please **UNPLUG** Mewt from your computer's USB before continuing.
   1. Navigate to where you extracted **mewt.zip** from ***Terminal***
   1. Type in ***python3 linux_install_mewt.py***, wait for the prompt to plug in your Mewt
   1. When you plug in your Mewt, the prompt will disappear.  Your Mewt may flash a white light briefly.  After a short delay, Mewt will light up with a steady Blue.  _Based on your system/Arduino setup, it may take 15-20 seconds for the steady light to come on._
   1. Run **pacmd list-sources** to list all audio devices in your system.  
   1. With [online-voice-recorder.com](https://online-voice-recorder.com/) running, iterate through your sources with the below command until you identify the one that will correctly mute your microphone
   **pacmd set-source-mute X 1** _where X = your source number.  Start with 0 and work upwards_
   1. Once you have identified your microphone, **grep pacmd linux_mewt.py** to find the 2 instances where it's called and replace the microphone index.
   * Here are some links to get you started when you inevitably run into dependency/libraries/access issues
   * [How to install python3-pip on ubuntu 20.04](https://stackoverflow.com/questions/62317653/how-to-install-python3-pip-on-ubuntu-20-04)
   * [SerialException: could not open port /dev/ttyACM0](https://github.com/purduesigbots/pros-cli/issues/45)
   * [Command to mute and unmute a microphone](https://askubuntu.com/questions/12100/command-to-mute-and-unmute-a-microphone)
   </details>
   
</details>

## Running Mewt
<details>
 <summary>Click to expand</summary>
 
 
* Windows
  <details>
   <summary>Click to expand</summary>
   
   1. In _**File Explorer**_ navigate to _**C:\mewt**_
   1. To run Mewt in Headless/No-User-Interface mode, run **start_mewt.bat**
   ![startmewt](/images/screenshots/windows/startmewt.png)
   * To exit from Headless/No-User-Interface mode, simply unplug your Mewt from the USB port
   1. To run Mewt in Verbose mode, run **start_mewt_verbose.bat**.  This will open a console that will provide more information.
   ![startmewtverbose](/images/screenshots/windows/startmewtverbose.png)
   ![mewtverbose](/images/screenshots/windows/mewtverbose.png)
   * To exit from Verbose mode, you can hit ***Ctrl+C***, or close the ***PowerShell*** window or simply unplug your Mewt from the USB port
   * The very first time you use Mewt, you will need to press the button twice in order to activate it (sorry, it's a bug, still a work-in-progress). After it has been activated, every single button press will turn the primary microphone in your system from Unmuted to Muted, and vice versa.
   
   </details> 
 
* Mac
  <details>
   <summary>Click to expand</summary>
   
   1. Open ***Terminal*** from ***Finder->Applications->Utilities->Terminal***
   1. In the Terminal console, navigate to where you unzipped **mewt.zip** _typically this is **cd $HOME/Downloads/mewt**_
   1. Type in ***python mewt.py***
   ![mewtready](/images/screenshots/mac/mewtready.png)
   * To exit from Verbose mode, you can hit ***Ctrl+C***, or close the ***PowerShell*** window or simply unplug your Mewt from the USB port
   * The very first time you use Mewt, you will need to press the button twice in order to activate it (sorry, it's a bug, still a work-in-progress). After it has been activated, every single button press will turn the primary microphone in your system from Unmuted to Muted, and vice versa.
   * After you exit Mewt from the terminal, the light on the button will stay on until you restart Mewt or you unplug Mewt from the USB port
   </details>

* Linux
  <details>
   <summary>Click to expand</summary>
   
   1. Open ***Terminal*** 
   1. In the Terminal console, navigate to where you unzipped **mewt.zip**
   1. Type in ***python3 linux_mewt.py***
   * The very first time you use Mewt, you will need to press the button twice in order to activate it (sorry, it's a bug, still a work-in-progress). After it has been activated, every single button press will turn the primary microphone in your system from Unmuted to Muted, and vice versa.
   * After you exit Mewt from the terminal, the light on the button will stay on until you restart Mewt or you unplug Mewt from the USB port
   </details> 
</details>

## Make your enclosure
<details>
 <summary>Click to expand</summary>
</details>   
   
</details>
</details>

# How does the Mewt code work
<details>
 <summary>Click to expand</summary>
</details>


# How you can support Mewt
<details>
 <summary>Click to expand</summary>
 
 All I ask is that you take a moment to do something kind.  
  
 * Think of what you would have been willing to contribute to the Mewt project (however small the amount), and donate that to your favorite charity instead.
 
 * See someone hungry or cold?  Buy them a small meal or cheap socks.
 
 * Have elderly neighbors?  Offer to help shovel their driveway or mow their lawn.
 
 * People across the political divide have you on edge?  Bake them some cookies just to be nice.
 
 * Even something as simple as given a random stranger your best smile.  
 
 If you can report back via this 5 second [#UnMewtForGood questionnaire](https://www.surveymonkey.com/r/DFHGL6H), it would really make my day.  I'm hoping we can push out $1000 and/or 100 hours of kindness from this little corner of the internet.
 </details>


