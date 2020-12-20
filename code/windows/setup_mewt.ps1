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
Copy-Item ".\mewt.ps1" $mewt_path 
Copy-Item ".\setup_mewt.ps1" $mewt_path 
Copy-Item ".\AudioDeviceCmdlets.dll" $mewt_path

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

$form.close()

& .\mewt.ps1
# $process = start-Process -FilePath  powershell.exe -windowstyle hidden -file .\mewt.ps1

