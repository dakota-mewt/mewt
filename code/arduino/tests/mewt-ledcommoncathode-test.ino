const int led0 = 0;     
const int led1 = 1;     
const int led3 = 3;     
const int led4 = 4;     
const int led5 = 5;     
const int led6 = 6;     
const int led7 = 7;     
const int led8 = 8;     
const int led9 = 9;     
const int led10 = 10;     
const int led11 = 11;     
const int led12 = 12; 
const int led13 = 13; 
  
const int mewtButton = 2;     
      int mewtState = 0;
      byte inByte;     
      int inInt;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(led13, OUTPUT);
  pinMode(mewtButton, INPUT_PULLUP);   
}

// the loop function runs over and over again forever
void loop() {    
  digitalWrite(led0, HIGH);
  digitalWrite(led1, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
  digitalWrite(led11, HIGH);
  digitalWrite(led12, HIGH);
  digitalWrite(led13, HIGH);
  mewtState = digitalRead(mewtButton);

  if (mewtState == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);  
    Serial.println("pressed");      
    delay(50);
  }
  if (mewtState == HIGH) {
    digitalWrite(LED_BUILTIN, LOW);  
    Serial.println("released");      
    delay(50);
  }
}
