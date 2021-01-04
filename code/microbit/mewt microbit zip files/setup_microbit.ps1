$install_path = Get-Location
$install_path
$mewt_path = "c:\mewt\"

# checks if AudioDeviceCmdlets already exists in system
if (!(Test-Path "$($profile | split-path)\Modules\AudioDeviceCmdlets")) {

	# if not, installs AudioDeviceCmdlets locally
	New-Item "$($profile | split-path)\Modules\AudioDeviceCmdlets" -Type directory -Force
	Copy-Item ".\AudioDeviceCmdlets.dll" "$($profile | split-path)\Modules\AudioDeviceCmdlets\AudioDeviceCmdlets.dll"
	Set-Location "$($profile | Split-Path)\Modules\AudioDeviceCmdlets"
	Get-ChildItem | Unblock-File
	Import-Module .\AudioDeviceCmdlets
}	

cd $install_path
New-Item $mewt_path -Type directory -Force
Copy-Item ".\AudioDeviceCmdlets.dll" $mewt_path
Copy-Item ".\mewt.ps1" $mewt_path 
Copy-Item ".\start_mewt.bat" $mewt_path
Copy-Item ".\setup_microbit.bat" $mewt_path 
Copy-Item ".\setup_microbit.ps1" $mewt_path 
Copy-Item ".\start_mewt.bat" $mewt_path
Copy-Item ".\start_mewt_verbose.bat" $mewt_path
Copy-Item ".\mewt_microbit.hex" $mewt_path

cd $mewt_path

function popUp($text,$title) {
    $a = new-object -comobject wscript.shell
    $b = $a.popup($text,0,$title,0)
}

$serialportlist = New-Object Collections.Generic.List[String]
#write-host "Your current devices are:"

$COMportList = [System.IO.Ports.SerialPort]::getportnames() 

ForEach ($COMport in $COMportList) { 
$temp = new-object System.IO.Ports.SerialPort $COMport 
#echo $temp.PortName 
$serialportlist.add($temp.PortName)
$temp.Dispose() 
}
$serialportlistcount = $serialportlist.count

Add-Type -AssemblyName System.Windows.Forms 
$Form = New-Object system.Windows.Forms.Form
$Label = New-Object System.Windows.Forms.Label
$Form.Controls.Add($Label)
#$Label.Text = "Here are your current Serial ports: `n" + $COMportList + "`n`nPlease plug MEWT into a USB port"
$Label.Text = "Please plug MEWT into a USB port"
$Label.AutoSize = $True
$Form.Visible = $True
$Form.Update()

$mewtserialportlist = New-Object Collections.Generic.List[String]


$COMportList = [System.IO.Ports.SerialPort]::getportnames() 

ForEach ($COMport in $COMportList) { 
$temp = new-object System.IO.Ports.SerialPort $COMport 
#echo $temp.PortName 
$mewtserialportlist.add($temp.PortName)
$temp.Dispose() 
}

$mewtserialportlistcount = $mewtserialportlist.count

while ($serialportlistcount -ge $mewtserialportlistcount) {
	$mewtserialportlist = New-Object Collections.Generic.List[String]


	$COMportList = [System.IO.Ports.SerialPort]::getportnames() 

	ForEach ($COMport in $COMportList) { 
	$temp = new-object System.IO.Ports.SerialPort $COMport 
	#echo "while loops"
	$mewtserialportlist.add($temp.PortName)
	$temp.Dispose() 
	}
$mewtserialportlistcount = $mewtserialportlist.count
}
	$mewtserialportlist[$mewtserialportlistcount-1] | out-file .\mewt_com_port.txt -encoding ASCII
	write-host "Your MEWT is on " $mewtserialportlist[$mewtserialportlistcount-1]


#popUp $mewtserialportlist[$mewtserialportlistcount-1] "MEWT found on port hit OK to close"	

$microbit = gwmi win32_diskdrive | ?{$_.interfacetype -eq "USB"} | %{gwmi -Query "ASSOCIATORS OF {Win32_DiskDrive.DeviceID=`"$($_.DeviceID.replace('\','\\'))`"} WHERE AssocClass = Win32_DiskDriveToDiskPartition"} |  %{gwmi -Query "ASSOCIATORS OF {Win32_DiskPartition.DeviceID=`"$($_.DeviceID)`"} WHERE AssocClass = Win32_LogicalDiskToPartition"} | %{$_.deviceid}

write-host $microbit

$Label.Text = "Mewt detected `n`nSetting up your Mewt Microbit on " + $COMport + "`n`nPlease wait for the upload lights `non the underside of your Microbit to stop flashing"
$Form.Update()

Copy-Item ".\mewt_microbit.hex" $microbit

$form.close()



