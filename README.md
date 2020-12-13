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
</details>

# How to build it
## Get physical components
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
* **Wiring**: Common anode vs Common cathode.  Mewt works with either.  This just affects how you physically connect it to the Arduino.
* **Voltage**: 3V-6V are best as that is what Arduinos output.  I have had no issues with 12V.  I don't think Arduinos can drive 120/220V.
* **Resistor**: Buttons with built-in LEDs typically have resistors already and do not need separate resistors

**Other Examples**: 

_ |Latch | Momentary | Switch 
------------- | ------------- | ------------- | -------------
Basic | $3[![basiclatching](/images/basiclatching.png)](https://www.amazon.com/dp/B07WGNSRXR) | $3[![basicmomentary](/images/basicmomentary.png)](https://www.amazon.com/dp/B07VSFLTMJ) | $3[![basictoggleswitch](/images/basictoggleswitch.png)](https://www.amazon.com/dp/B07SXRKY6C/) 
Deluxe | $8[![deluxelatching](/images/deluxelatching.png)](https://www.amazon.com/gp/product/B07KQ3P2Y2) | $18[![deluxemomentary](/images/deluxemomentary.png)](https://www.ebay.com/itm/333311892227) | $10[![deluxetoggleswitch](/images/deluxetoggleswitch.png)](https://www.amazon.com/gp/product/B008DG7NWQ) 
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

### Naked Mewt
You may be interested in building a simplified version of Mewt because you don't want to solder, or because it is a good way to learn/experiment, or as a project for your kids.  If so, consider getting an Arduino starter kit instead

<details>
 <summary>Click to expand</summary> 
 
**Examples**: 
* $37[![arduinostarterkit](/images/arduinostarterkit.png)](https://www.amazon.com/dp/B01D8KOZF4/)

It will come with everything you need (Arduino, breadboard, wires, buttons, LEDs, resistors).  Plus you still have spare parts to make other projects when you're done!

Alternately, you can buy the Arduino/breadboard individually.  If you are getting a button without an LED, you will have to get a separate RGB to display Mute/Unmute state and Hot Mic visualizer
* $2[![rgb](/images/rgb.png)](https://www.amazon.com/dp/B07SJZGFBL/)

Naked LEDs require a resistor so they don't burn out

**Examples**:
* $5[![resistor](/images/resistor.png)](https://www.amazon.com/dp/B008UTW6JG/)

</details>

_Note: these are not referral links, I do not benefit from you clicking on these links.  I am not making an endorsement for Amazon or specific 3rd party merchants.  These are purely to help people get started_
