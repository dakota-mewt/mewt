# Mewt
Mewt allows you to create a **hardware button to Mute and Unmute all system microphones with a single click in Windows and Mac**.  

Mewt works at the operating system (OS) level, so this **will mute/unmute all conferencing software** (Zoom, Google Meet, Teams, WebEx, Blue Jeans, GoToMeeting, Skype, Slack, Facebook, Discord, etc.)

Mewt will **continuously display the current Mute/Unmute state** so you can tell at a glance if your microphone is enabled without having to search for the onscreen icon.

If your microphone is broadcasting, Mewt will also help you **avoid embarassing hot-mic incidents via RGB LED light indicator**.
Muted | Unmuted | Hot Mic
------------ | ------------- | -------------
![Mewted](/images/mewt.png) | ![Unmewted](/images/unmewt.png) | ![Hot Mic](/images/hotmic.gif)

# How it works
Mewt is made up of 2 parts: 
1. Physical components
   1. A physical button to control mute state 
   1. An RGB LED to display mute state / hot-mike
   1. An Arduino microcontroller to interface with the button and the LED and that communicates with the computer
1. Code running on your computer to 
   1. recognize button presses to toggle microphone mute/unmute
   1. read microphone mute/unmute state and send information to the physical components to display status
   1. read microphone volume levels and send information to the physical components to display hot-mic

# How to build it
## Get physical components
### 1. Get an Arduino (~$2 - $8)
Any Arduino model (Pro Micro, Nano, Uno, etc) should work.  Pick the USB connector of your choice (Micro-USB, Mini-USB, UBS-C), Mewt is agnostic.  
**Things to consider**:
* **Size**: Pro Micro is the smallest, followed closely by the Nano, Unos are pretty big
* **To solder or not**: if you don't want to solder, get an Uno or a Pro Micro/Nano with pre-soldered headers ![headers](/images/arduino-with-header.png) and a breadboard ![breadboard](/images/breadboard.png)
**Examples**: 

_ | Pro Micro | Nano | Nano 
------------ | ------------- | ------------- | -------------
Size | Smallest ![promicro](/images/promicro.png) | Slightly larger ![nano](/images/nano.png)| Large ![uno](/images/uno.png)
With Headers  | N/A |  [$5.59](https://www.amazon.com/dp/B082HGQ24C/) | [$10.69](https://www.amazon.com/dp/B016D5KOO)
Without Headers  | [$7.69](https://www.amazon.com/dp/B07J2Q3ZD5) | [$12.50](https://www.amazon.com/dp/B07VX7MX27) | N/A

_Note: these are not referral links, I do not benefit from you clicking on these links.  I am not making an endorsement for Amazon or specific 3rd party merchants.  These are purely to help people get started_
