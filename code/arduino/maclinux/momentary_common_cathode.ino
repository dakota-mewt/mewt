String inByte;          // reading serial for powershell commands
const int button1Pin = 2;  		// pushbutton 1 pin


const int unmewtledPin =  7;
const int mewtledPin =  4;

const int RED_PIN = 4;      // LED for visualizer
const int GREEN_PIN = 9;    // LED for visualizer
const int BLUE_PIN = 7;   // LED for visualizer

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
  Serial.setTimeout(50);    //decreases parseInt timeout 

  
}


void loop()
{
  int button1State, button2State;  // variables to hold the pushbutton states

  button1State = digitalRead(button1Pin);

    if (Serial.available() > 0) {
    inByte = Serial.readString();     
  float inBytefloat = inByte.toFloat();        
  ledDisplay = String(inByte).toFloat();		
		
		   if (ledDisplay == 0) {
          digitalWrite(unmewtledPin, LOW);
          digitalWrite(LED_BUILTIN, LOW);
          digitalWrite(mewtledPin, HIGH);
          digitalWrite(RED_PIN, HIGH);
          digitalWrite(GREEN_PIN, LOW);
          digitalWrite(BLUE_PIN, LOW);
        }
        else if (ledDisplay == 1) {
          digitalWrite(unmewtledPin, HIGH);
          digitalWrite(LED_BUILTIN, LOW);
          digitalWrite(mewtledPin, LOW);
          digitalWrite(RED_PIN, LOW);
          digitalWrite(GREEN_PIN, LOW);
          digitalWrite(BLUE_PIN, HIGH);           
        }
        else if (ledDisplay == 2) {
          digitalWrite(unmewtledPin, HIGH);
          digitalWrite(LED_BUILTIN, LOW);
          digitalWrite(mewtledPin, LOW);
          digitalWrite(RED_PIN, LOW);
          digitalWrite(GREEN_PIN, HIGH);
          digitalWrite(BLUE_PIN, LOW);           
        }
     else if (ledDisplay == 101) {
          digitalWrite(unmewtledPin, HIGH);
          digitalWrite(LED_BUILTIN, HIGH);
          digitalWrite(mewtledPin, HIGH);          
          digitalWrite(RED_PIN, LOW);
          digitalWrite(GREEN_PIN, HIGH);
          digitalWrite(BLUE_PIN, LOW); 
          delay(300);
          digitalWrite(unmewtledPin, LOW);
          digitalWrite(LED_BUILTIN, LOW);
          digitalWrite(mewtledPin, LOW);    
          digitalWrite(RED_PIN, LOW);
          digitalWrite(GREEN_PIN, LOW);
          digitalWrite(BLUE_PIN, LOW); 
          delay(200);
          digitalWrite(unmewtledPin, HIGH);
          digitalWrite(LED_BUILTIN, HIGH);
          digitalWrite(mewtledPin, HIGH);          
          digitalWrite(RED_PIN, LOW);
          digitalWrite(GREEN_PIN, HIGH);
          digitalWrite(BLUE_PIN, LOW); 
          delay(300);
          digitalWrite(unmewtledPin, LOW);
          digitalWrite(LED_BUILTIN, LOW);
          digitalWrite(mewtledPin, LOW);          
          digitalWrite(RED_PIN, LOW);
          digitalWrite(GREEN_PIN, LOW);
          digitalWrite(BLUE_PIN, LOW); 
          delay(200);   
          digitalWrite(unmewtledPin, HIGH);
          digitalWrite(LED_BUILTIN, HIGH);
          digitalWrite(mewtledPin, HIGH);          
          digitalWrite(RED_PIN, LOW);
          digitalWrite(GREEN_PIN, HIGH);
          digitalWrite(BLUE_PIN, LOW); 
          delay(300);
          digitalWrite(unmewtledPin, LOW);
          digitalWrite(LED_BUILTIN, LOW);
          digitalWrite(mewtledPin, LOW);          
          digitalWrite(RED_PIN, LOW);
          digitalWrite(GREEN_PIN, LOW);
          digitalWrite(BLUE_PIN, LOW); 
        }      
        else if ((ledDisplay % 3) == 0) {
          digitalWrite(unmewtledPin, HIGH);
          digitalWrite(LED_BUILTIN, LOW);
          digitalWrite(mewtledPin, LOW);          
          digitalWrite(RED_PIN, HIGH);
          digitalWrite(GREEN_PIN, LOW);
          digitalWrite(BLUE_PIN, HIGH); 
        }
        else if (ledDisplay % 3 == 1) {
          digitalWrite(unmewtledPin, HIGH);
          digitalWrite(LED_BUILTIN, LOW);
          digitalWrite(mewtledPin, LOW);          
          digitalWrite(RED_PIN, HIGH);
          digitalWrite(GREEN_PIN, HIGH);
          digitalWrite(BLUE_PIN, LOW); 
        }
        else if (ledDisplay % 3 == 2) {
          digitalWrite(unmewtledPin, HIGH);
          digitalWrite(LED_BUILTIN, LOW);
          digitalWrite(mewtledPin, LOW);          
          digitalWrite(RED_PIN, HIGH);
          digitalWrite(GREEN_PIN, HIGH);
          digitalWrite(BLUE_PIN, HIGH); 
        }
    //timestamps last MEWT display update
  lastLedDisplayUpdate = millis();        
  }

  //if it's been over 1 second since last MEWT display update, turn off LEDs to avoid confusion   
  //if(millis() - lastLedDisplayUpdate > 1000) {
  //        digitalWrite(unmewtledPin, LOW);
  //        digitalWrite(mewtledPin, LOW);             
  //        digitalWrite(RED_PIN, LOW);
  //        digitalWrite(GREEN_PIN, LOW);          
  //        digitalWrite(BLUE_PIN, LOW);  
  //}       

  
  if (button1State == LOW)  // if we're pushing button 1 
  {
    // turn on LED to indicate button pressed, turn off all other LEDs
    digitalWrite(unmewtledPin, LOW);
    digitalWrite(mewtledPin, LOW);             
    digitalWrite(RED_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);      
    digitalWrite(GREEN_PIN, HIGH);          
    // wait for bounce    
  delay(200);

    //read button state again to see if button has been released or if it's still depressed
  button1State = digitalRead(button1Pin);


  //if button has been released, then check for togglestate change
  if (button1State == HIGH) {  
	if (toggleState == 0) {
		toggleState = 1;
	}
	else {
  		toggleState = 0;
	}
     Serial.println(toggleState);
  }
  }
 }
