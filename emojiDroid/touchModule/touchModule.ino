// Variable Setup 
int capValue[5];
int capSense[5];
int ledPins[5];

void setup() {

  // Pin designation
  capSense[0] = 14; // (should be moved to analog read if we want to measure anything)
  capSense[1] = 15; // (A0-A4)
  capSense[2] = 16;
  capSense[3] = 17;
  capSense[4] = 18;
  ledPins[0] = 5; //These are analog out pins (PWM)
  ledPins[1] = 9; 
  ledPins[2] = 10;
  ledPins[3] = 11; 
  ledPins[4] = 12;

  // Set up pin I/O
  for (int i=0;i<5;i++) { 
    pinMode(capSense[i], INPUT);
    pinMode(ledPins[i], OUTPUT);
  }

  // Initialize Serial 
  Serial.begin(9600);
}

void loop() {

  // Trigger LEDs with Capacitor Touch Values
  for (int i=0;i<5;i++) { // looping through all sensor inputs
    
    capValue[i] = digitalRead(capSense[i]); // get value from capacitor sensor
    
    if (capValue[i] != 0) { // High recieved
      digitalWrite(ledPins[i], LOW); 
      Serial.print("on"); 
      
    } else { // Low received
      digitalWrite(ledPins[i], HIGH); 
    }
  }
}
