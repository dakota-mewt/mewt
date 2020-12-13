# Mewt
Mewt allows you to create a **hardware button to Mute and Unmute all system microphones with a single click in Windows and Mac**.  

Mute/unmute occurs at the system level, so this **works for all conferencing software** (Zoom, Google Meet, Teams, WebEx, Blue Jeans, GoToMeeting, Skype, Slack, Facebook, Discord, etc.)

Mewt will **continuously display the current Mute/Unmute state** so you can tell at a glance if your microphone is enabled without having to search for the onscreen icon.

If your microphone is broadcasting, Mewt will also help you **avoid embarassing hot-mic incidents via RDB LED display**.
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
1. Get physical components
   1. Get an Arduino (~$2 - $8)
Any Arduino model (Pro Micro, Nano, Uno, etc) should work.  Pick the USB connector of your choice (Micro-USB, Mini-USB, UBS-C), Mewt is agnostic.  
**Things to consider**:
* **Size**: Pro Micro is the smallest, followed closely by the Nano, Unos are pretty big
* **To solder or not**: if you don't want to solder, get an Uno or a Pro Micro/Nano with pre-soldered headers ![headers](/images/arduino-with-header.png) and a breadboard ![breadboard](/images/breadboard.png)
