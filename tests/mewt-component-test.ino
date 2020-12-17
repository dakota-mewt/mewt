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
const int led14 = 14;     
const int led15 = 15;     
const int led16 = 16;     
const int led17 = 17;     
const int led18 = 18;     
const int led19 = 19;     
const int led20 = 20;     
const int led21 = 21;     

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
  pinMode(led14, OUTPUT);
  pinMode(led15, OUTPUT);
  pinMode(led16, OUTPUT);
  pinMode(led17, OUTPUT);
  pinMode(led18, OUTPUT);
  pinMode(led19, OUTPUT);
  pinMode(led20, OUTPUT);
  pinMode(led21, OUTPUT);
  pinMode(mewtButton, INPUT_PULLUP);   
}

// the loop function runs over and over again forever
void loop() {    
  digitalWrite(led0, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
  digitalWrite(led11, LOW);
  digitalWrite(led12, LOW);
  digitalWrite(led13, LOW);
  digitalWrite(led14, LOW);
  digitalWrite(led15, LOW);
  digitalWrite(led16, LOW);
  digitalWrite(led17, LOW);
  digitalWrite(led18, LOW);
  digitalWrite(led19, LOW);
  digitalWrite(led20, LOW);
  digitalWrite(led21, LOW);
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
