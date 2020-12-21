String inByte;					// reading serial for powershell commands
const int button1Pin = 2;  		// pushbutton 1 pin

const int RED_PIN = 4;			// LED for visualizer
const int GREEN_PIN = 7;		// LED for visualizer
const int BLUE_PIN = 9;		// LED for visualizer

int toggleState = 1;
unsigned long lastLedDisplayUpdate;
float lastVolume;
int ledDisplay;

void setup()
{
  // Set up the pushbutton pins to be an input:
  pinMode(button1Pin, INPUT_PULLUP);
  

  // Set up the LEDs pin to be an outputs:
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  // Set up the serial bus
  Serial.begin(9600);  
  Serial.setTimeout(50);		//decreases parseInt timeout 
  
}


void loop()
{
  int button1State, button2State;  // variables to hold the pushbutton states

  button1State = digitalRead(button1Pin);
  
  

    //if there is data to display, whether it is volume or mewt state
    if (Serial.available())  {
      inByte = Serial.readString();

      
        // blink unmewt light if volume level changes.  I can only seem to compare this delta if they are both Bytes and not int.
   float inBytefloat = inByte.toFloat();

/*   if (inBytefloat != lastVolume) {
    digitalWrite(GREEN_PIN, HIGH);  // turn the LED off
    delay (50);
    digitalWrite(GREEN_PIN, LOW);  // turn the LED off    
    delay (50);
    digitalWrite(GREEN_PIN, HIGH);  // turn the LED off
   }
   lastVolume = inBytefloat; 
*/    

  //changes Byte to string and then to int in order to faciltate comparison and lcd display
   ledDisplay = String(inByte).toFloat();

        if (ledDisplay == 0) {
          digitalWrite(RED_PIN, HIGH);
          digitalWrite(LED_BUILTIN, LOW);
          digitalWrite(GREEN_PIN, LOW);
          digitalWrite(BLUE_PIN, LOW);
        }
        else if (ledDisplay == 1) {
          digitalWrite(RED_PIN, LOW);
          digitalWrite(LED_BUILTIN, LOW);
          digitalWrite(GREEN_PIN, LOW);
          digitalWrite(BLUE_PIN, HIGH);          
        }

     else if (ledDisplay == 101) {
          digitalWrite(LED_BUILTIN, HIGH);
          digitalWrite(RED_PIN, LOW);
          digitalWrite(GREEN_PIN, HIGH);
          digitalWrite(BLUE_PIN, LOW); 
          delay(300);
          digitalWrite(LED_BUILTIN, LOW);
          digitalWrite(RED_PIN, LOW);
          digitalWrite(GREEN_PIN, LOW);
          digitalWrite(BLUE_PIN, LOW); 
          delay(200);
          digitalWrite(LED_BUILTIN, HIGH);
          digitalWrite(RED_PIN, LOW);
          digitalWrite(GREEN_PIN, HIGH);
          digitalWrite(BLUE_PIN, LOW); 
          delay(300);
          digitalWrite(LED_BUILTIN, LOW);
          digitalWrite(RED_PIN, LOW);
          digitalWrite(GREEN_PIN, LOW);
          digitalWrite(BLUE_PIN, LOW); 
          delay(200);
          digitalWrite(LED_BUILTIN, HIGH);
          digitalWrite(RED_PIN, LOW);
          digitalWrite(GREEN_PIN, HIGH);
          digitalWrite(BLUE_PIN, LOW); 
          delay(300);
          digitalWrite(LED_BUILTIN, LOW);
          digitalWrite(RED_PIN, LOW);
          digitalWrite(GREEN_PIN, LOW);
          digitalWrite(BLUE_PIN, LOW); 
        }      
        else if ((ledDisplay % 3) == 0) {
          digitalWrite(RED_PIN, HIGH);
          digitalWrite(LED_BUILTIN, LOW);
          digitalWrite(GREEN_PIN, LOW);
          digitalWrite(BLUE_PIN, HIGH);  
        }
        else if (ledDisplay % 3 == 1) {
          digitalWrite(RED_PIN, LOW);
          digitalWrite(LED_BUILTIN, LOW);
          digitalWrite(GREEN_PIN, HIGH);
          digitalWrite(BLUE_PIN, HIGH); 
        }
        else if (ledDisplay % 3 == 2) {
          digitalWrite(RED_PIN, LOW);
          digitalWrite(LED_BUILTIN, LOW);
          digitalWrite(GREEN_PIN, HIGH);
          digitalWrite(BLUE_PIN, LOW);  
        }
    //timestamps last MEWT display update
  lastLedDisplayUpdate = millis();
  }
     

  //if it's been over 1 second since last MEWT display update, turn off LEDs to avoid confusion   
  //if(millis() - lastLedDisplayUpdate > 1000) {
  //        digitalWrite(RED_PIN, LOW);
  //        digitalWrite(GREEN_PIN, LOW);          
  //        digitalWrite(BLUE_PIN, LOW);     
  //}  
	
  if (button1State != toggleState) // if we're pushing button 1 
  {
  // send value to powershell to mewt
      Serial.println(button1State); 
      toggleState = button1State;
  // delay removes button bounce
 	    delay(5);      		
  }

  
  
}
