// Connect all LEDs and button to digital pins
int counterPin1 = 10;                          
int counterPin2 = 11;                          
int counterPin3 = 12;
int counterPin4 = 13;      
int savePin1 = 6;                          
int savePin2 = 7;                          
int savePin3 = 8;
int savePin4 = 9;                  
int buttonPin = 2;    

// Initialize counterPinState, savePinState, and buttonState variables to off
boolean counterPin1State = LOW;
boolean counterPin2State = LOW;
boolean counterPin3State = LOW;
boolean counterPin4State = LOW;
boolean savePin1State = LOW;
boolean savePin2State = LOW;
boolean savePin3State = LOW;
boolean savePin4State = LOW;
boolean buttonState = LOW;

// Set each pin as OUTPUT or INPUT
void setup() {
   pinMode(counterPin1,OUTPUT);        
   pinMode(counterPin2,OUTPUT);      
   pinMode(counterPin3,OUTPUT);      
   pinMode(counterPin4,OUTPUT);
   pinMode(savePin1,OUTPUT);        
   pinMode(savePin2,OUTPUT);      
   pinMode(savePin3,OUTPUT);      
   pinMode(savePin4,OUTPUT);
   pinMode(buttonPin,INPUT);                                                    
}


void loop() {
// Visual Test
  for (byte vis_counter=0; vis_counter<=15; vis_counter++) {
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
    digitalWrite(savePin1,counterPin1State);
    digitalWrite(savePin2,counterPin2State);
    digitalWrite(savePin3,counterPin3State);
    digitalWrite(savePin4,counterPin4State);
    break;
    }
    else {
    dectobinary(vis_counter);
    delay(250);
    }
  }

  // Auditory Test
  delay(2000);
  tone(3,60);
  for (byte aud_counter=0; aud_counter<=15; aud_counter++) {
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
    noTone(3);
    digitalWrite(counterPin1,counterPin1State);
    digitalWrite(counterPin2,counterPin2State);
    digitalWrite(counterPin3,counterPin3State);
    digitalWrite(counterPin4,counterPin4State);
    break;
    }
    else {
    dectobinary(aud_counter);
    delay(250);
    }
  }
  exit(0);
}                                  

// Custom Decimal to Binary Conversion function
void dectobinary(byte number) {
  if (bitRead(number,0) == 1) {
    digitalWrite(counterPin1,HIGH);
    counterPin1State = HIGH;
  }
  else {
    digitalWrite(counterPin1,LOW);
    counterPin1State = LOW;
  }
  if (bitRead(number,1) == 1) {
    digitalWrite(counterPin2,HIGH);
    counterPin2State = HIGH;
  }
  else {
    digitalWrite(counterPin2,LOW);
    counterPin2State = LOW;
  }
  if (bitRead(number,2) == 1) {
    digitalWrite(counterPin3,HIGH);
    counterPin3State = HIGH;
  }
  else {
    digitalWrite(counterPin3,LOW);
    counterPin3State = LOW;
  }
  if (bitRead(number,3) == 1) {
    digitalWrite(counterPin4,HIGH);
    counterPin4State = HIGH;
  }
  else {
    digitalWrite(counterPin4,LOW);
    counterPin4State = LOW;
  }
}