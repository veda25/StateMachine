// Variable Setup 
int capValue[5];
int capSense[5];
int ledPins[5];

void setup() {

  // Pin designation
  capSense[0] = 8;
  capSense[1] = 9;
  capSense[2] = 10;
  capSense[3] = 11;
  capSense[4] = 12;
  ledPins[0] = 2;
  ledPins[1] = 3;
  ledPins[2] = 4;
  ledPins[3] = 5;
  ledPins[4] = 6;

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
