#include <Servo.h>

// Variable Setup 
int capValue[5];
int capSense[5];
int capThreshold;
int ledPins[5];
int testAngle;
int emojiToggle;
int emojiState;
int activeServos;
int servoDirection[4];
int servoAngle[4];
int armMin;
int armMax;
int analogIn;
Servo roboServo[4];

void setup() {

  // Servo Setup
  roboServo[0].attach(7); // Pin 7: fullServo
  roboServo[1].attach(3); // Pin 3: handServo
  //roboServo[2].attach(); // rotatorServo 
  //roboServo[3].attach(); // shoulderServo 
  for (int i=0;i<5;i++) {
    servoDirection[i] = 1; // (-'ve is opposite direction, can be increased if code changed below...)
  }
  activeServos = 1; //(+1)

  // Emoji State (and LEDS)
  emojiToggle = 0; // 0 = unpressed, 1 = pressed
  emojiState = 0; // loops after 4...
  capThreshold = 0; 
  analogIn = 0; // Mode: analog or digital
  armMin = 20;
  armMax = 160;

  // Pin references
  if (analogIn) {
    capSense[0] = A0; 
    capSense[1] = A1; 
    capSense[2] = A2;
    capSense[3] = A3;
    capSense[4] = A4;
  } else {
    capSense[0] = 14; 
    capSense[1] = 15;
    capSense[2] = 16;
    capSense[3] = 17;
    capSense[4] = 18;
  }
  ledPins[0] = 6; //These are analog out pins (PWM)
  ledPins[1] = 9; 
  ledPins[2] = 10;
  ledPins[3] = 11; 
  ledPins[4] = 12;

  // Set up pin I/O
  for (int i=0;i<5;i++) { 
    pinMode(capSense[i], INPUT);
    pinMode(ledPins[i], OUTPUT);
  }

  // Default Serial Value (9600)
  Serial.begin(9600);
}

void loop() {

  // Trigger LEDs with Capacitor Touch Values
  for (int i=0;i<5;i++) { // looping through all sensor inputs

    if (analogIn) { // Analog or digital read
      capValue[i] = analogRead(capSense[i]); // get value from capacitor sensor
      capValue[i] = map(capValue[i], 0, 1023, 0, 255);
    } else { 
      capValue[i] = digitalRead(capSense[i]);
    }
    
    if (capValue[i] > capThreshold) { // High recieved

      // Activate Emoji Toggle
      if (i == 0) {
        
        // Should toggle-trigger a state change 
        if (emojiToggle == 0) {
          emojiState++;

          Serial.println("Toggle Flag\n");
          
          if (emojiState >= 5) { // Loop Emoji State
            emojiState = 0;  
          }
        emojiToggle = 1;
        }
        
      } else if (i < activeServos) { 

        Serial.println("Servo\n");

        // Flip Direction at Limits
        if ((servoAngle[i] <= armMin && servoDirection[i] == -1) || (servoAngle[i] >= armMax && servoDirection[i] == 1)) {
          servoDirection[i] *= -1;    
          
        }
        // Increment servo angle
        servoAngle[i] += servoDirection[i];

        // Apply angle to servo
        roboServo[i].write(servoAngle[i]);
        
      }
      
    } else { // Low received
        
      // Turn off toggle
      if (emojiToggle == 1) {
        emojiToggle = 0;  
      }
    }

    if (i == emojiState) { // Emoji Light
      // Move to target angle for select emoji
      if (servoAngle[0] > emojiState * 72) {
        servoAngle[0]--;
      } else if (servoAngle[0] < emojiState * 72) {
        servoAngle[0]++;
      } else if (servoAngle[0] == emojiState * 72) {
        // drive LED
        Serial.println("Active\n");
        if (analogIn) {
          analogWrite(ledPins[emojiState], capValue[i]); 
        } else {
          digitalWrite(ledPins[emojiState], HIGH);
        }
      }
      
    } else { // Unused LEDs
      if (analogIn) {
        analogWrite(ledPins[i], 0);  
      } else {
        digitalWrite(ledPins[i], LOW);  
      } 
    }
  }

  
}
