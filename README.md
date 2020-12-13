# Mewt
Mewt allows you to create a **hardware button to Mute and Unmute all system microphones with a single click in Windows and Mac**.  

Mute/unmute occurs at the system level, so this **works for all conferencing software** (Zoom, Google Meet, Teams, WebEx, Blue Jeans, GoToMeeting, Skype, Slack, Facebook, Discord, etc.)

Mewt will **continuously display the current Mute/Unmute state** so you can tell at a glance if your microphone is enabled without having to search for the onscreen icon.

If your microphone is broadcasting, Mewt will also help you **avoid embarassing hot-mic incidents via RDB LED display**.

# How it works
Mewt is made up of 2 parts: 
1. Pysical components
* A physical button to control mute state 
* an RGB LED to display mute state / hot-mike
* an Arduino microcontroller to interface with the button and the LED and that communicates with the computer
2. Code running on your computer to 
* recognize button presses to toggle microphone mute/unmute
* read microphone mute/unmute state and send information to the physical components to display status
* read microphone volume levels and send information to the physical components to display hot-mic

