String inByte;          // reading serial for powershell commands
const int button1Pin = 2;      // pushbutton 1 pin


const int unmewtledPin =  7;
const int mewtledPin =  6;  // on the original RED_PIN was 4, I kept them the same.

const int RED_PIN = 6;      	// LED for visualizer
const int GREEN_PIN = 5;    	// LED for visualizer
const int BLUE_PIN = 4;   	// LED for visualizer
const int FAKE_GND = 3;      	// LED for visualizer - basically uses the pin as GND

const int BLINK_INTERVAL = 30000;	// 30 secs

int toggleState = 1;
unsigned long lastLedDisplayUpdate;
float lastVolume;
int ledDisplay;

// nice pattern of changing colors for indication.
// rounds is the number of times it will play the pattern, default is 1.
// delay_millis is the time each color plays, default is 0.2 sec.
// you can etiher define both or just "rounds". function will not work with just delay_millis (that is how C++ works)
void RGB_rainbow(int rounds=1, int delay_millis=200) {
  for (int i=0; i< rounds; i++){
    RGB_color(HIGH, LOW, LOW); // Red
    delay(delay_millis);
    RGB_color(LOW, HIGH, LOW); // Green
    delay(delay_millis);
    RGB_color(LOW, LOW, HIGH); // Blue
    delay(delay_millis);
    RGB_color(HIGH, HIGH, 0); // Raspberry
    delay(delay_millis);
    RGB_color(LOW, HIGH, HIGH); // Cyan
    delay(delay_millis);
    RGB_color(HIGH, LOW, HIGH); // Magenta
    delay(delay_millis);
    RGB_color(HIGH, HIGH, LOW); // Yellow
    delay(delay_millis);
    RGB_color(HIGH, HIGH, HIGH); // White
    delay(delay_millis);
  }
}


void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  digitalWrite(RED_PIN, red_light_value);
  digitalWrite(GREEN_PIN, green_light_value);
  digitalWrite(BLUE_PIN, blue_light_value);
}


void setup()
{
  // Set up the pushbutton pins to be an input:
  pinMode(button1Pin, INPUT_PULLUP);   // MEANS THE BUTTON IS CONNECTED TO A PIN ON ONE SIDE, AND TO GND ON THE OTHER SIDE!
  
  // Set up the LEDs pin to be an outputs:
  pinMode(LED_BUILTIN, OUTPUT);

  
  pinMode(FAKE_GND, OUTPUT);
  digitalWrite(FAKE_GND, LOW);
  	
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  // Set up the serial bus
  Serial.begin(9600);  
  Serial.setTimeout(50);    //decreases parseInt timeout 
  RGB_rainbow(3);  // do fun stuff while loading, indocating setup is done propely
  
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
       // RED
			  RGB_color(HIGH, LOW, LOW);
			}
			else if (ledDisplay == 1) {
			  digitalWrite(unmewtledPin, HIGH);
			  digitalWrite(LED_BUILTIN, LOW);
			  digitalWrite(mewtledPin, LOW);
        // BLUE
			  RGB_color(LOW, LOW, HIGH); 
			}
			else if (ledDisplay == 2) {
			  digitalWrite(unmewtledPin, HIGH);
			  digitalWrite(LED_BUILTIN, LOW);
			  digitalWrite(mewtledPin, LOW);
        // GREEN 
			  RGB_color(LOW, HIGH, LOW);

			}
		 else if (ledDisplay == 101) {
			  digitalWrite(unmewtledPin, HIGH);
			  digitalWrite(LED_BUILTIN, HIGH);
			  digitalWrite(mewtledPin, HIGH);   
        // GREEN       
			  RGB_color(LOW, HIGH, LOW);
			  delay(300);
			  digitalWrite(unmewtledPin, LOW);
			  digitalWrite(LED_BUILTIN, LOW);
			  digitalWrite(mewtledPin, LOW);    
	   // ALL OFF
			  RGB_color(LOW, LOW, LOW);
			  delay(200);
			  digitalWrite(unmewtledPin, HIGH);
			  digitalWrite(LED_BUILTIN, HIGH);
			  digitalWrite(mewtledPin, HIGH);          
       // GREEN
			  RGB_color(LOW, HIGH, LOW);
 
			  delay(300);
			  digitalWrite(unmewtledPin, LOW);
			  digitalWrite(LED_BUILTIN, LOW);
			  digitalWrite(mewtledPin, LOW);          
   	// ALL OFF
			  RGB_color(LOW, LOW, LOW); 
			  delay(200);   
			  digitalWrite(unmewtledPin, HIGH);
			  digitalWrite(LED_BUILTIN, HIGH);
			  digitalWrite(mewtledPin, HIGH);        
       	// GREEN
			  RGB_color(LOW, HIGH, LOW);
			  delay(300);
			  digitalWrite(unmewtledPin, LOW);
			  digitalWrite(LED_BUILTIN, LOW);
			  digitalWrite(mewtledPin, LOW);    
   	// ALL OFF
			  RGB_color(LOW, LOW, LOW); 
			}      
			else if ((ledDisplay % 3) == 0) {
			  digitalWrite(unmewtledPin, HIGH);
			  digitalWrite(LED_BUILTIN, LOW);
			  digitalWrite(mewtledPin, LOW);    
        //  RED+BLUE      
			  RGB_color(HIGH, LOW, HIGH);  
			}
			else if (ledDisplay % 3 == 1) {
			  digitalWrite(unmewtledPin, HIGH);
			  digitalWrite(LED_BUILTIN, LOW);
			  digitalWrite(mewtledPin, LOW);          
        //  RED+GREEN      
			  RGB_color(HIGH, HIGH, LOW); 
			}
			else if (ledDisplay % 3 == 2) {
			  digitalWrite(unmewtledPin, HIGH);
			  digitalWrite(LED_BUILTIN, LOW);
			  digitalWrite(mewtledPin, LOW);          
        //  RED+GREEB+BLUE     
			  RGB_color(HIGH, HIGH, HIGH); 
			}
		//timestamps last MEWT display update
	  lastLedDisplayUpdate = millis();        
  }

  //if it's been over 1 second since last MEWT display update, turn off LEDs to avoid confusion 
  if(millis() - lastLedDisplayUpdate > 1000) {
          digitalWrite(unmewtledPin, LOW);
          digitalWrite(mewtledPin, LOW);  
          
		  // if Mewt is connected properly, but script (or some software-related component) isn't running
		  // the RGB blinks every 30 seconds to indicate Mewt is fine. feel free to change the BLINK_INTERVAL at the top.
		  if(((millis() - lastLedDisplayUpdate)%BLINK_INTERVAL)==0){
            RGB_rainbow(1,30);
          }           
	   // ALL OFF
		  RGB_color(LOW, LOW, LOW); 
  }       

  
  if (button1State == LOW)  // if we're pushing button 1 
  {
    // turn on LED to indicate button pressed, turn off all other LEDs
    digitalWrite(unmewtledPin, LOW);
    digitalWrite(mewtledPin, LOW); 
	
       // GREEN
	RGB_color(LOW, HIGH, LOW);         
    // wait for bounce    
  delay(300);

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
