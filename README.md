# Mewt
Mewt allows you to create a **hardware button to Mute and Unmute all system microphones with a single click in Windows, Mac and Linux**.  

Mewt works at the operating system (OS) level, so this **will mute/unmute all conferencing software** (Zoom, Google Meet, Teams, WebEx, Blue Jeans, GoToMeeting, Skype, Slack, Facebook, Discord, etc.)

Mewt will **continuously display the current Mute/Unmute state** so you can tell at a glance if your microphone is enabled without having to search for the onscreen icon. _currently works in Windows and Mac, but not Linux_

If your microphone is broadcasting, Mewt will also help you **avoid embarassing hot-mic incidents via RGB LED light indicator**. _currently works in Windows, but not Mac or Linux_

Muted | Unmuted | Hot Mic
------------ | ------------- | -------------
![Mewted](/images/mewt.png) | ![Unmewted](/images/unmewt.png) | ![Hot Mic](/images/hotmic.gif)

# How it works
<details>
 <summary>Click to expand</summary> 

Mewt is made up of 2 parts: 
   
1. Physical components
   1. A physical button to control mute state, with a built-in RGB LED to display mute state / hot-mic
   1. An Arduino microcontroller to interface with the button and the LED. This is also what will communicate with your computer
1. Code running on your computer to 
   1. recognize button presses to toggle microphone mute/unmute
   1. read microphone mute/unmute state and send information to the physical components to display status
   1. read microphone volume levels and send information to the physical components to display hot-mic
![mewtdesign](/images/mewtdesign.png)

</details>

# How to build it
## Get physical components
<details>
 <summary>Click to expand</summary>

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
  ------------- | ------------- | ------------- | -------------
  Basic | $3![basiclatching](/images/basiclatching.png)](https://www.amazon.com/dp/B07WGNSRXR) | $3![basicmomentary](/images/basicmomentary.png)](https://www.amazon.com/dp/B07VSFLTMJ) | $3![basictoggleswitch](/images/basictoggleswitch.png)](https://www.amazon.com/dp/B07SXRKY6C/) 
  Deluxe | $8![deluxelatching](/images/deluxelatching.png)](https://www.amazon.com/gp/product/B07KQ3P2Y2) | $18![deluxemomentary](/images/deluxemomentary.png)](https://www.ebay.com/itm/333311892227) | $10![deluxetoggleswitch](/images/deluxetoggleswitch.png)](https://www.amazon.com/gp/product/B008DG7NWQ) 
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

  _ | Pro Micro | Nano | Nano 
  ------------ | ------------- | ------------- | -------------
  Size | Smallest ![promicro](/images/promicro.png) | Slightly larger ![nano](/images/nano.png)| Large ![uno](/images/uno.png)
  With Headers  | N/A |  [$6](https://www.amazon.com/dp/B082HGQ24C/) | [$11](https://www.amazon.com/dp/B016D5KOO)
  Without Headers  | [$8](https://www.amazon.com/dp/B07J2Q3ZD5) | [$13](https://www.amazon.com/dp/B07VX7MX27) | N/A
  </details>


### 3. Get wires, solder, soldering iron

You may be interested in building a simplified version of Mewt because you don't want to solder, or because it is a good way to learn/experiment, or as a project for your kids. 
  <details>
   <summary>If so, click here to expand</summary> 

### Basic Mewt

**Get an Arduino Starter Kit**: 
* $20[![arduinostarterkit](/images/arduinostarterkit.png)](https://www.amazon.com/dp/B01DGD2GAO/)

It will come with everything you need (Arduino, breadboard, wires, buttons, LEDs, resistors).  Plus you still have spare parts to make other projects when you're done!

 </details>
 
_Note: these are not referral links, I do not benefit from you clicking on these links.  I am not making an endorsement for Amazon or specific 3rd party merchants.  These are purely to help people get started_
</details>

## Test physical components
<details>
 <summary>Click to expand</summary>

### 1. Plug in your Arduino and find its COM port
* Windows
  <details>
   <summary>Click to expand</summary>
 
   1. click Start 
   [![clickstart](/images/screenshots/windows/clickstart.png)]
   1. type in **_device manager_** to search and open 
   ![devicemanager](/images/screenshots/windows/devicemanager.png)
   1. scroll down to **_ports_** and expand it.  _Note: you may not see a Ports listing until after the next step, don't panic._
   1. now plug your Arduino into your computer's USB port.  Depending on your Arduino model, you may see some lights blink on your Arduino at this point.
   1. the **_Device Manager_** window may refresh at this point.  scroll down to **_ports_**, and expand it (again).
   1. you should see a listing for **_Arduino [specific model] (COMx)_** where **_x_** is usually a number from 3 - 15 
   ![ports](/images/screenshots/windows/ports.png)
   1. jot down the COMx serial port somewhere, we'll need to reference it later
   * _If you do not see your Arduino here, or if you see a question mark icon, we will need to [Troubleshoot](#Troubleshooting)_
   </details>

* Mac
  <details>
   <summary>Click to expand</summary>
   
   1. click **_Finder->Applications->Utilities->Terminal_** 
   ![terminal](/images/screenshots/mac/terminal.png)
   1. in the Terminal window, type in **_ls /dev/tty.*_** and hit enter. Make a mental note of the results.  
   ![portsbeforearduino](/images/screenshots/mac/portsbeforearduino.png)
   1. now plug your Arduino into your computer's USB port.  Depending on your Arduino model, you may see some lights blink on your Arduino at this point.
   1. in the Terminal window, type in **_ls /dev/tty.*_** and hit enter (again). 
   ![portsafterarduino](/images/screenshots/mac/portsafterarduino.png)
   1. jot down the new entry **_/dev/tty.XXXXXXXX_** serial port somewhere, we'll need to reference it later
   </details>
 

* Linux
  <details>
   <summary>Click to expand</summary>
   
   1. in a Terminal window, type in **_ls /dev/tty.*_** and hit enter. Make a mental note of the results.  
   ![portsbeforearduino](/images/screenshots/mac/portsbeforearduino.png)
   1. now plug your Arduino into your computer's USB port.  Depending on your Arduino model, you may see some lights blink on your Arduino at this point.
   1. in the Terminal window, type in **_ls /dev/tty.*_** and hit enter (again). 
   ![portsafterarduino](/images/screenshots/mac/portsafterarduino.png)
   1. jot down the new entry **_/dev/tty.XXXXXXXX_** serial port somewhere, we'll need to reference it later
   </details>

### 2. Download and install the Arduino IDE to test your Arduino
<details>
 <summary>Click to expand</summary>

1. go to [The Arduino Download Page](https://www.arduino.cc/en/software) to download the latest IDE for your OS
1. install and launch the IDE
1. select **_File->New_** and delete everything in the new window that opens up
1. select **_Tools->Board_** and choose your Arduino model.  _for Pro Micros, choose Arduino Leonardo_ 
![boards](/images/screenshots/arduino/boards.png)
1. select **_Tools->Ports_** and choose the same serial port that you jotted down earlier 
![portselection](/images/screenshots/arduino/portselection.png)
1. in the editor window paste in this code borrowed from **Abdullah Al Mamun** from [Instructables.com](https://www.instructables.com/Arduino-Function-Serialread-And-SerialreadString/) 
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

1. select **_Sketch->Verify/Compile_**.  You can click **_Save_** when it prompts you to save the sketch folder.  
![verifycompile](/images/screenshots/arduino/verifycompile.png)
1. you should see a green **Done Compiling** status at the bottom of your Arduino window 
![donecompiling](/images/screenshots/arduino/donecompiling.png)
1. select **_Sketch->Upload_**.
![upload](/images/screenshots/arduino/upload.png)
1. you should see the status change to **Uploading**, the lights on the Arduino should blink, followed by a green **Done Uploading** status at the bottom of your Arduino window. 
![doneuploading](/images/screenshots/arduino/doneuploading.png)
1. if you get an error while uploading, some Arduino models require you to select your Bootloader.  To do that, select **_Tools->Processor->(Old Bootloader)_** and try uploading again.  
![processorbootloader](/images/screenshots/arduino/processorbootloader.png)
1. select **_Tools->Serial Monitor_** 
![serialmonitor](/images/screenshots/arduino/serialmonitor.png)
1. make sure the 2 selections on the lower right hand of the screen are: **Both NL & CR** and **9600 baud** 
![serialmonitorparameter](/images/screenshots/arduino/serialmonitorparameter.png)
1. in the text box, type in **_Hello World_** and click **_Send_**
1. if all goes well, you should see the same words show up below the text box next to a timestamp 
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
* in the editor window paste in [this code](/tests/mewt-component-test.ino) 
  
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
   const int led14 = 14;     
   const int led15 = 15;     
   const int led16 = 16;     
   const int led17 = 17;     
   const int led18 = 18;     
   const int led19 = 19;     
   const int led20 = 20;     
   const int led21 = 21;     

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
     pinMode(led14, OUTPUT);
     pinMode(led15, OUTPUT);
     pinMode(led16, OUTPUT);
     pinMode(led17, OUTPUT);
     pinMode(led18, OUTPUT);
     pinMode(led19, OUTPUT);
     pinMode(led20, OUTPUT);
     pinMode(led21, OUTPUT);
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
     digitalWrite(led14, HIGH);
     digitalWrite(led15, HIGH);
     digitalWrite(led16, HIGH);
     digitalWrite(led17, HIGH);
     digitalWrite(led18, HIGH);
     digitalWrite(led19, HIGH);
     digitalWrite(led20, HIGH);
     digitalWrite(led21, HIGH);
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

1. select **_Sketch->Verify/Compile_**.  You can click **_Save_** when it prompts you to save the sketch folder.  
![verifycompile](/images/screenshots/arduino/verifycompile.png)
1. you should see a green **Done Compiling** status at the bottom of your Arduino window 
![donecompiling](/images/screenshots/arduino/donecompiling.png)
1. select **_Sketch->Upload_**.  
![upload](/images/screenshots/arduino/upload.png)
1. you should see the status change to **Uploading**, the lights on the Arduino should blink, followed by a green **Done Uploading** status at the bottom of your Arduino window. 
![doneuploading](/images/screenshots/arduino/doneuploading.png)
1. if you get an error while uploading, some Arduino models require you to select your Bootloader.  To do that, select **_Tools->Processor->(Old Bootloader)_** and try uploading again.  
![processorbootloader](/images/screenshots/arduino/processorbootloader.png)
1. select **_Tools->Serial Monitor_** 
![serialmonitor](/images/screenshots/arduino/serialmonitor.png)
1. make sure the 2 selections on the lower right hand of the screen are: **Both NL & CR** and **9600 baud** 
![serialmonitorparameter](/images/screenshots/arduino/serialmonitorparameter.png)
1. if all goes well, you should see the word **pressed** in the output window every time you press the button.  It should display **released** when you let go of the button.
![buttontest](/images/screenshots/arduino/buttontest.png)
1. if you get the opposite result of what you are looking for (output says **pressed** when you release the button and it says **released** when you press the button), simply swap the wires connecting to the button terminals
1. **Congratulations** if this is your first time connecting a piece of physical hardware to your code!  Go get another gummi bear and shove it in your face! 

 <details>
  <summary>
   
   _Curious as to what the program did?_
   </summary>
It sets a variable (**mewtButton**) to the Arduino #2 pin, and creates a variable (**mewtState**).  

It sets the Serial speed to be 9600, and a timeout of 50 (milliseconds).  The default timeout is 1 second, so a 50 millisecond time will allow faster responses from the Arduino.

We also initialize **LED_BUILTIN** (Arduino's built-in LED) and the MewtButton.  **INPUT_PULLUP** uses Arduino's built-in resistor so you can avoid having to physically wire in a resistor to make the button work.

_ignore all the references to **led**, those are for later when we test the LEDs_

Inside the infinite loop, we read the current state from **mewtButton**, which is reading from Arduino's #2 pin, and puts it into **mewtState** variable.  

Then we check the value of the state.  If it is **LOW**, then that means that the button has been pressed.  We then output that state by turning on **LED_BUILTIN** and also write **pressed** on the serial port to be displayed by the computer.  That will happen as long as the button is pressed.

If we release the button, then **mewtState** would be **HIGH**.  We then output that state by turning off **LED_BUILTIN** and also write **released** on the serial port to be displayed by the computer.  That will happen as long as the button is pressed.
 </details>

</details>
</details>



### 4. Test your LED 
<details>
 <summary>Click to expand</summary>

* **Common Cathode vs Common Anode**: Here's a [link that explains](https://forum.arduino.cc/index.php?topic=22413.0) it.

**If LED is Common Cathode**
   <details>
   <summary>Click to expand</summary>
      
   * A Common (sometimes labeled **C**) - you will connect this to **GND** on your Arduino
   * A Terminal for every color LED in your light - You will connect these to one of the **D** pins on your Arduino (for example: red -> D4)
   ![ledtestwiring-commoncathode](/images/ledtestwiring-commoncathode.png)
   </details>

**If LED is Common Anode**
   <details>
   <summary>Click to expand</summary>
   
   * A Common (sometimes labeled **C**) - you will connect this to **VCC** or **5V** on your Arduino
   * A Terminal for every color LED in your light - You will connect these to one of the **D** pins on your Arduino (for example: red -> D4)
   ![ledtestwiring-commonannode](/images/ledtestwiring-commonannode.png)
   </details>

* if your Arduino is already running the program to test your button from above, then you should see your LED 
LED
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

