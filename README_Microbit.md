# Mewt Microbit
Mewt allows you to create a **hardware button to Mute and Unmute all system microphones with a single press for Windows, Mac and Linux**.  

Mewt works at the operating system (OS) level, so this **will mute/unmute all conferencing software** (Zoom, Google Meet, Teams, WebEx, Blue Jeans, GoToMeeting, Skype, Slack, Facebook, Discord, etc.)

Mewt will **continuously display the current Mute/Unmute state** so you can tell at a glance if your microphone is enabled without having to search for the onscreen icon. 

When Mewt detects that your microphone is transmitting audio, it will display a sound visualizer to help you **avoid embarassing hot-mic incidents via RGB LED light indicator**. _Hot mic currently works in Windows, but not yet in Mac or Linux_

![mewtdemo](/images/mewtdemomicrobitlowrez.gif)

Muted | Unmuted | Hot Mic
:------------: | :-------------: | :-------------:
![mewt](/images/mewt/microbitmewted.jpg) | ![unmewt](/images/mewt/microbitunmewted.jpg) | ![Hot Mic](/images/mewt/microbithotmic.gif)

# How Mewt works
<details>
 <summary>Click to expand</summary> 

Mewt is made up of 2 parts: 
   
1. Physical components
   1. Physical buttons to control mute state, with a built-in LED to display mute state / hot-mic
   1. A Microbit microcontroller to interface with the button and the LED. This is also what will communicate with your computer
1. Code running on your computer to 
   1. Recognize button presses to toggle microphone mute/unmute
   1. Read microphone mute/unmute state and send information to the Microbit to display status
   1. Read microphone volume levels and send information to the Microbit to display hot-mic
![mewtdesign](/images/mewtdesign.png)

</details>

# How to build Mewt
<details>
 <summary>Click to expand</summary>


## Get a Microbit (both V1 and V2 should work)
_Note: these are not referral links, I do not benefit from you clicking on these links.  I am not making an endorsement for any merchant.  These are purely to help people get started_
* $15[![microbit](/images/mewt/microbitmewted.jpg)](https://www.adafruit.com/product/3530)

## Connect your computer to your Mewt Microbit
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
 
TO BE UPDATED


</details>   

</details>

# How does the Mewt code work
<details>
 <summary>Click to expand</summary>
 
* **Arduino**
   <details>
    <summary>Click to expand</summary>
   Mewt's Arduino code wires the below inputs, outputs and placeholders together:

   **Input from user**
     * Button: User issues command to Mewt to mute/unmute microphone by pressing the button

   **Output to computer**
     * Serial: Arduino opens up a communications channel to pass along the user input via commands to the computer.  1=mute, 0=unmute

   **Input from computer**
     * Serial: After the computer issues the command to mute/unmute the system microphone, it passes a value to Arduino to represent the current state of the microphone.  0=muted, 1=umuted.  It is also possible to receive values >1 if the computer supports streaming microphone volume data (for hot-mic support).  

   **Output to user**
     * LED: Arduino takes the input from computer and maps them into different colors to be displayed to the user via the combination of RGB LED lights.  

      Value | Meaning | RGB | Color
     :------------: | :-------------: | :-------------: |  :-------------: 
     0 | Muted | R | Red
     1 | Unmuted | B | Blue
     2 | Button pressed | G | Green
     mod 3 = 0 (3, 6, 9, etc.) | Hot-mic | RB | Purple
     mod 3 = 1 (4, 7, 10, etc.) | Hot-mic | RG | Yellow
     mod 3 = 2 (5, 8, 11, etc.) | Hot-mic | RGB | White
     101 | There's a change to the system audio devices | G G G | Flashes green 3x

   **Placeholders**
     * toggleState: for momentary buttons, this help to keep track of whether the last button press resulted in a mute or an unmute, since you cannot read this off the button itself
     * lastLedDisplayUpdate: keeps track of when the last udpate came in from the computer, helps it figure out when Mewt is no longer running on the computer
     * lastVolume: keeps track of the previous volume.  This is currently deprecated.  It was previously used to detect volume changes to allow a single LED light to be flickered for Hot-mic if there was no RGB available
     * ledDisplay: holds the value received from the computer and is used to determine which color LED to light

   **Pseudocode**
     * Read current state of button
     * Read value from computer
     * Figure out what RGB to turn on depending on value from computer
     * Timestamps last value from computer
     * If it's been longer than 1 second since last value from computer, shut down all LEDs to avoid user confusion
     * If button was pressed, turn on Green LED to provide feedback to user
     * Read current state of button again
     * If button was previously pressed, and is now released, then user has toggled mute/unmute.  Save mute state to memory.  Send command via serial to computer.



   </details>

* **Windows**
   <details>
    <summary>Click to expand</summary>

   Mewt Windows leverages the AudioDeviceCmdlets PowerShell library for its communications with system microphones.  See [Acknowledgments](#Acknowledgments)

   **Setup Pseudocode**
     * Reads command line arguments *Passing **Zoom** or **Meet** as an argument will make Mewt attempt to send the shortcut for application-level muting respectively
     * Reads the COM port to look for Mewt on from **mewt_com_port.txt**.  *should have been detected and written as part of the setup*
     * Imports AudioDeviceCmdlets library
     * If it's the first time Mewt/AudioDeviceCmdlets has run on this computer, it will install/copy the files to the correct directories for future use
     * Opens a separate process to output the volume stream of the current microphone to a file **out.txt**
     * Creates a Serial bus communicatioons using the COM port from above
     * Sends **101** to Mewt to display flashing green light to indicate Mewt is starting up
     * Clears the console and outputs ***Mewt Ready*** *for verbose mode*
     * Declares some temporary variables to keep state for last button state and ***unmewtable device*** *I encountered USB microphone that unmuted itself right after a mute command was sent that needed specialized treatment*
     * Takes a snapshot of all system audio devices, filtered down to just the microphones/recording devices
     * Starts a timer to gauge how long each press is taking to effect *for verbose mode*

   **Loop Pseudocode**
     * Take the last value from audio stream and write it to **mewt_stream.txt**
     * Queries current mute state from computer and inverts it *AudioDeviceCmdlets returns 1 for mute, but Mewt sends 0 for mute in order to more logically support hot-mic
     * If current state is unmuted, but microphone is capturing no volume, AudioDeviceCmdlets returns 0.  Replace this 0 to 1 before sending to Mewt
     * Otherwise, send last volume value to Mewt
     * Check against previous mute state to prevent unnecessary commands *sending mute when microphone is currently muted*
     * Read button state from Arduino
     * Timestamps mute state change start
     * If we received **Zoom** or **Meet** from command line argument, then switch windows focus to Zoom or Google Chrome respectively and send appropriate shortcut key *the Chrome tab that Meet is on has to be the in-focus tab for this to work*
     * Iteratives through each available system microphone and mutes them individually, making sure to save the primary microphone, and checking if there's been a change of devices *removed a device or added a device*
     * For every microphone muted/unmuted, timestamps how long it took from start to finish
     * Checks for ***unmewtable device*** *if user wants to mute, and we muted every microphone, but a microphone subsequently reports that it's unmuted*
     * Waits for a fraction over half a second and mutes that unmewtable device again *beats me why this works, it just does*
     * Once we have discovered an unmewtable device, we will save it so that we don't waste time checking it every time.  Mewt will go directly to doing a 2nd mute attempt on these devices
     * Exits if port to Arduino no longer active *if Mewt is physically unplugged*

   </details>


* **Mac**
   <details>
    <summary>Click to expand</summary>

   Mewt Mac leverages AppleScript in order to set the recording volume of the primary microphone to 0 for mute, and 100 for unmute.  *There is a more robust way to actually mute microphones (as opposed to setting volume to 0), and to iterate through each microphone.  To do so, we can leverage the **Audio MIDI Setup** application.  However, this currently takes 3-5 seconds per toggle and is not efficient enough to use without further optimization.  

   **Setup Pseudocode**
     * Reads the COM port to look for Mewt on from **port_arduino**.  *should have been detected and written as part of the setup*
     * Creates a Serial bus communicatioons using the COM port from above
     * Declares some temporary variables to keep state for last button state  
     * Sends **101** to Mewt to display flashing green light to indicate Mewt is starting up  
     * Clears the console

   **Loop Pseudocode**
     * Read button state from Arduino
     * _test_data.csv_ refers to hot-mic feature that is currently being tested and not yet integrated
     * If 1 received, then mute by calling **mac_native_mewt.scpt** AppleScript
     * Otherwise, if 0 received, then unmute by calling **mac_native_unmewt.scpt** AppleScript
     * Write 1/0 for mute/unmute to serial so Arduino can display the correct status lights
   </details>


* **Linux**
   <details>
    <summary>Click to expand</summary>

   Mewt Linux was tested on Ubuntu 20.04 LTS and 18.04LTS.  It leverages the PulseAudio library for its communications with system microphones.  See [Acknowledgments](#Acknowledgments)  *The code currently mutes/unmutes a single microphone as opposed to iterating through every single device.  Since you're a Linux user, have at it!*  

   **Setup Pseudocode**
     * Reads the COM port to look for Mewt on from **port_arduino**.  *should have been detected and written as part of the setup*
     * Creates a Serial bus communicatioons using the COM port from above
     * Declares some temporary variables to keep state for last button state  
     * Sends **101** to Mewt to display flashing green light to indicate Mewt is starting up  
     * Clears the console

   **Loop Pseudocode**
     * Read button state from Arduino
     * _test_data.csv_ refers to hot-mic feature that is currently being tested and not yet integrated
     * If 1 received, then mute by calling **pacmd set-source-mute _X_ 1** _where X is microphone to be muted
     * Otherwise, if 0 received, then unmute by calling **pacmd set-source-mute _X_01** _where X is microphone to be unmuted
     * Write 1/0 for mute/unmute to serial so Arduino can display the correct status lights
   </details>
</details>

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

# Questions/Comments/Help
Join me on the [Mewt Discord](https://discord.gg/aGfKgpkcu9)

# Acknowledgments
<details>
 <summary>Click to expand</summary>
 
* Mewt's Windows implementation leverages the [AudioDeviceCmdlets](https://github.com/frgnca/AudioDeviceCmdlets) library, Copyright &copy; 2016-2018 Francois Gendron <fg@frgn.ca>
* Mewt's Linux implementation leverages the [PulseAudio](https://www.freedesktop.org/wiki/Software/PulseAudio/About/) library.  
* Mewt's Windows Self-Extracting Executable file makes use of the [Shushing Face Icon](https://openmoji.org/library/#emoji=1F92B) from the [OpenMoji](https://openmoji.org/about/#acknowledgement) project.  
</details>
