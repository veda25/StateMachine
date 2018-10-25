#include <Servo.h>

// Variable Setup 
int capValue[5];
int capSense[5];
int ledPins[5];
Servo servo1;
int servo_1_angle;
Servo servo2;
int servo_2_angle;

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

  //servo1.attach(7);
  servo2.attach(3);
  servo_1_angle = 0;
  servo_2_angle = 10;
  //servo1.write(servo_1_angle);
  servo2.write(servo_2_angle);

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
      
    } else { // Low received
      digitalWrite(ledPins[i], HIGH); 
        /*
        if (i == 1) {
          servo_1_angle++;
          if (servo_1_angle >= 360) {
            servo_1_angle = 0;
            }
          servo1.write(servo_1_angle);
          delay(15);
        } 
        */
        if (i == 2) {
          servo_2_angle++;
          if (servo_2_angle > 180) {
            servo_2_angle = 10;
            }
          if (servo_2_angle <= 10) {servo_2_angle = 180;}
          servo1.write(servo_2_angle);
          delay(15);
        }
        
    }
  }
}

