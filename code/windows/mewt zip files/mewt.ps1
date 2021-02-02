$param=$args[0]

$mewt_port = Get-Content -path ".\mewt_com_port.txt" -tail -1
	Import-Module .\AudioDeviceCmdlets

# checks if AudioDeviceCmdlets already exists in system
if (!(Test-Path "$($profile | split-path)\Modules\AudioDeviceCmdlets")) {

	# if not, installs AudioDeviceCmdlets locally
	New-Item "$($profile | split-path)\Modules\AudioDeviceCmdlets" -Type directory -Force
	Copy-Item ".\AudioDeviceCmdlets.dll" "$($profile | split-path)\Modules\AudioDeviceCmdlets\AudioDeviceCmdlets.dll"
	Set-Location "$($profile | Split-Path)\Modules\AudioDeviceCmdlets"
	Get-ChildItem | Unblock-File
	Import-Module .\AudioDeviceCmdlets
}

# starts writing volume stream to temporary file.
 $process = start-Process -FilePath powershell.exe -nonewwindow 'import-module .\audiodevicecmdlets; Write-AudioDevice -RecordingStream | out-file .\out.txt' -passthru
#$port.close()
$port = new-Object System.IO.Ports.SerialPort $mewt_port,9600,None,8,one
$port.DTREnable = $True
$port.RTSEnable = $True
$port.ReadTimeout = 50
$port.open()

$port.Write([int]101)
clear
write-host "MEWT ready"

# sets up initial state for later comparison
$previous_button_value = -1
$unmewtable_device = -1

# takes a snapshot of the reocrding devices in the system for later comparison
$audio_device_list = Get-AudioDevice -list
$recording_devices_old = $audio_device_list | ? {$_.Type -eq "Recording"}
$out_timer =  [system.diagnostics.stopwatch]::StartNew()
$out_timer.start()
$loop = 1

while ($port.IsOpen)
{
	$mewt_stream_txt_file = ".\mewt_stream.txt"
	$mewt_stream_txt_file_path = [System.IO.Path]::Combine($mewt_stream_txt_file)
	$FileMode = [System.IO.FileMode]::OpenOrCreate
	$FileAccess = [System.IO.FileAccess]::Write
	$FileShare = [IO.FileShare]::Read

	# reads last volume value written
	$last_mewt_stream_value = Get-Content -path ".\out.txt" -tail 1

	# skips non-integer values, and explicit types the output as int
	if (($last_mewt_stream_value -ne $null) -and ($last_mewt_stream_value.gettype().name -eq "String")) {
		$last_mewt_stream_value = [int]$last_mewt_stream_value

		# writes value to mewt_stream.txt
		$FileStream = New-Object IO.FileStream($mewt_stream_txt_file_path, $FileMode, $FileAccess, $FileShare)
		$StreamWriter = New-Object System.IO.StreamWriter($FileStream)
		$StreamWriter.WriteLine($last_mewt_stream_value)
		$StreamWriter.flush()
		$streamWriter.close()
	}

	# gets mewt state, if mewted preps 0 to be sent to arduino
	try  {$current_mewt_state = Get-AudioDevice -RecordingMute -erroraction SilentlyContinue}
	Catch [System.exception] {"faulty audio device"}
	#$_.exception.gettype().fullname}

	if ($process.HasExited) {$process = start-Process -FilePath powershell.exe  'Write-AudioDevice -RecordingStream | out-file .\out.txt' -passthru}
	
	if ($current_mewt_state) {
		$send_value_to_arduino = "0"
	} else {
		$send_value_to_arduino = "1"
	}

	# reads last button pushed by arduino
	try {$value_from_arduino = $port.ReadLine()}
	Catch [System.exception] {}
#write-host $value_from_arduino
	# holds mewt state in variable.  we are inverting the mewt state because we are sending 0 to arduino to indicate mute=true
	$opposite_mewt_state = $send_value_to_arduino
	
	
	# if state is mewted, send 0 to arduino to trigger red light
	if ([int]$send_value_to_arduino -eq 0) {
		$mewt_stream = [int]0

	# otherwise, if unmewted, get the latest volume value
	} else {
		$mewt_stream = Get-Content -path ".\mewt_stream.txt" -head 1

		# replaces 0 (no volume value) with 1, to avoid collision with arduino mewt representation
		if ([int]$mewt_stream -eq 0) {
			$mewt_stream = [int]1
		}

	
	
	}
	# send volume value to arduino
	try {$port.writeline([int]$mewt_stream)}
	Catch [System.exception] {"No audio data"}

	# if a value is read from arduino, that means there's a button push
	#if (($value_from_arduino.length -gt 0) -and ($previous_button_value -ne [int]$value_from_arduino.Substring($value_from_arduino.length-1))){
	if (($value_from_arduino.length -gt 0) -and ($previous_button_value -ne [int]$value_from_arduino)){
		$value_from_arduino = [int]$value_from_arduino
		$previous_button_value = $value_from_arduino
		
		# if value read is the same as $opposite_mewt_state, that means that a change in state was requested
		if ($value_from_arduino -eq $opposite_mewt_state) {

$stopwatch =  [system.diagnostics.stopwatch]::StartNew()
$stopwatch

if ($param -eq "Zoom") {
$wshell = New-Object -ComObject wscript.shell;
if ($wshell.AppActivate('Zoom Meeting')) {
	$wshell.SendKeys('%a')
	}
if ($wshell.AppActivate('Meeting Controls')) {
	$wshell.SendKeys('%a')
	}
}

if ($param -eq "Meet") {
$wshell = New-Object -ComObject wscript.shell;
$wshell.AppActivate('Google Chrome')
$wshell.SendKeys('^d')
}

if ($param -eq "Discord") {
$wshell = New-Object -ComObject wscript.shell;
$wshell.AppActivate('Discord')
$wshell.SendKeys('^+d')
}

#$stopwatch
			# clears the console output
			clear

			# prints out requested mewt state
			if ($value_from_arduino -eq 0) {
				write-host "===========UNMEWTING===========" 
#$serial |Write-ArduinoSerial [int]0		
#write-host "0"		
			} else {
			write-host "============MEWTING============" 
#$stopwatch
#$serial |Write-ArduinoSerial [int]1
#write-host "1"		
#$stopwatch
			}

			# following is from the old mewt.ps1
		
			# gets the list of all audio devices
			try  {$current_mewt_state = $audio_device_list = Get-AudioDevice -list -erroraction SilentlyContinue}
			Catch [System.exception] {"faulty audio device"}
	#			$_.exception.gettype().fullname}

if ($process.HasExited) {$process = start-Process -FilePath powershell.exe  'Write-AudioDevice -RecordingStream | out-file .\out.txt' -passthru}

			# grabs only the recording devices, ignoring playback
			$recording_devices = $audio_device_list | ? {$_.Type -eq "Recording"}
			
			# compares the latest recording devices snapshot against the previous
			$recording_devices_changed = Compare-Object -ReferenceObject $recording_devices_old -DifferenceObject $recording_devices
			$recording_devices_changed = $recording_devices_changed | out-string -stream | select-string "inputobject"
			
			# if the recording_devices list has changed, then resets the unmewtable_device to unknown, the current recording_devices list is saved for later comparison
			if (!!$recording_devices_changed) {
				$unmewtable_device = -1
				$recording_devices_old = $recording_devices
			}
			
			# saves the default_recording_device for later reinstatement
			$default_recording_device = $recording_devices | ? {$_.Default -eq $True}

			# grabs only the index of the recording devices
			$recording_device_index = $recording_devices.Index | Out-String -stream

			# for each index, mewts the device
			foreach ($i in $recording_device_index) {

				# converts the string to an int
				$inti = [int]$i

				# changes default audio device to the current iteration, nonverbose
				try  {Set-AudioDevice $inti | out-null -erroraction SilentlyContinue}
				Catch [System.exception] {"faulty audio device"}
	#				$_.exception.gettype().fullname}					

if ($process.HasExited) {$process = start-Process -FilePath powershell.exe  'Write-AudioDevice -RecordingStream | out-file .\out.txt' -passthru}

				# if input is 1, mutes.  if it's 0, unmutes
				try  {Set-AudioDevice -RecordingMute $value_from_arduino -erroraction SilentlyContinue}
				Catch [System.exception] {"faulty audio device"}
	#				$_.exception.gettype().fullname}

if ($process.HasExited) {$process = start-Process -FilePath powershell.exe  'Write-AudioDevice -RecordingStream | out-file .\out.txt' -passthru}				

#debug output to check for elapsed time
write-host "toggle mewt state device #" $inti ": " $stopwatch.Elapsed.Seconds"."$stopwatch.Elapsed.Milliseconds
			} 	# foreach ($i in $recording_device_index) {
				# for each index, mewts the device

#debug output to display unmewtable device id
write-host "unmewtable device ID#" $unmewtable_device " " $out_timer.Elapsed.Days "days" $out_timer.Elapsed.Hours "hours" $out_timer.Elapsed.Minutes "minutes" $out_timer.Elapsed.Seconds "seconds"
		
			#this should only one time, the first time, to check to see if there are unmewtable devices
			if (($unmewtable_device -eq -1) -and ($value_from_arduino -eq 1)) {
$port.Write([int]101)
			write-host "check whether there is an unmewtable device "  				
				start-sleep -seconds 0.51
				foreach ($i in $recording_device_index) {

					# converts the string to an int
					$inti = [int]$i

					# changes default audio device to the current iteration, nonverbose
					
					try  {Set-AudioDevice $inti | out-null -erroraction SilentlyContinue}
					Catch [System.exception] {"faulty audio device"}
	#					$_.exception.gettype().fullname}						

if ($process.HasExited) {$process = start-Process -FilePath powershell.exe  'Write-AudioDevice -RecordingStream | out-file .\out.txt' -passthru}

					# writes the name of the device
					try  {$audio_device_name = Get-AudioDevice $inti | out-string -stream | select-string "name" -erroraction SilentlyContinue}
					Catch [System.exception] {"faulty audio device"}
	#					$_.exception.gettype().fullname}		
					
if ($process.HasExited) {$process = start-Process -FilePath powershell.exe  'Write-AudioDevice -RecordingStream | out-file .\out.txt' -passthru}
					
					$audio_device_name = $audio_device_name -split ":"
					$audio_device_name = $audio_device_name[1]
					
					# gets the recordingmute value
					try  {$mewtstate =  Get-AudioDevice -RecordingMute -erroraction SilentlyContinue}
					Catch [System.exception] {"faulty audio device"}
	#					$_.exception.gettype().fullname}

if ($process.HasExited) {$process = start-Process -FilePath powershell.exe  'Write-AudioDevice -RecordingStream | out-file .\out.txt' -passthru}

					# if true, writes "mewted", otherwise "unmewted"
					if ($mewtstate -eq $false) { 
						#write-host "UNMEWTED " $audio_device_name.Trim() ":" $stopwatch.Elapsed.Seconds"."$stopwatch.Elapsed.Milliseconds `n
						$unmewtable_device = $inti
					} 
					else {
						#write-host "MEWTED "  $audio_device_name.Trim() ":" $stopwatch.Elapsed.Seconds"."$stopwatch.Elapsed.Milliseconds `n
					}
				}
			write-host $stopwatch.Elapsed.Seconds"."$stopwatch.Elapsed.Milliseconds
			}

			#after the first mewt attempt, if there is no unmewtable device discovered, set it to 0 so we never have to check again
			if (($unmewtable_device -eq -1) -and ($value_from_arduino -eq 1)) {
				$unmewtable_device = 0
			}
		

			#if we have an unmewtable_device in the system, then this will mewt that device last, after the appropriate delay
			if (([int]$unmewtable_device -gt 0) -and ([int]$value_from_arduino -eq 1)){
				#read-host "inside unmewtable " $unmewtable_device
				
				try  {set-audiodevice $unmewtable_device -erroraction SilentlyContinue}
				Catch [System.exception] {"faulty audio device"}
	#				$_.exception.gettype().fullname}

if ($process.HasExited) {$process = start-Process -FilePath powershell.exe  'Write-AudioDevice -RecordingStream | out-file .\out.txt' -passthru}
				
				start-sleep -seconds 0.51
				try  {Set-AudioDevice -RecordingMute 1 -erroraction SilentlyContinue}
				Catch [System.exception] {"faulty audio device"}
	#				$_.exception.gettype().fullname}

if ($process.HasExited) {$process = start-Process -FilePath powershell.exe  'Write-AudioDevice -RecordingStream | out-file .\out.txt' -passthru}				

				write-host "toggle mewt state device #" $unmewtable_device ": " $stopwatch.Elapsed.Seconds"."$stopwatch.Elapsed.Milliseconds
			}

		} 	# if ($value_from_arduino -eq $mewt_state) {
			# if value read is the same as mewt_state, that means that a change in state was requested
			
		
		
	}  	#if ($value_from_arduino.length -gt 0) {
		#if a value is read from arduino, that means there's a button push	
#if ($out_timer.Elapsed.hours -gt 10) {$process.Kill(); $loop = 0;import-module .\audiodevicecmdlets;$mewt_process = start-Process -FilePath powershell.exe  '.\mewt.ps1'}
}
$process.kill()
write-host "MEWT exiting"