const int mewtButton = 2;     
   int mewtState = 0;
   byte inByte;     
   int inInt;

void setup() {
Serial.begin(9600);
Serial.setTimeout(50);
// initialize digital pin LED_BUILTIN as an output.
pinMode(LED_BUILTIN, OUTPUT);
pinMode(mewtButton, INPUT_PULLUP);   
}

// the loop function runs over and over again forever
void loop() {    
mewtState = digitalRead(mewtButton);

if (mewtState == LOW) {
  digitalWrite(LED_BUILTIN, HIGH);  
  Serial.println("pressed");      
  delay(500);
}
if (mewtState == HIGH) {
  digitalWrite(LED_BUILTIN, LOW);  
  Serial.println("released");      
  delay(500);
}
delay(500);
}
