#include <Servo.h>

#define SERVO_A 7 // Note: no semicolons in macro definitions
#define SERVO_B 8 

// Variable Setup 
int capValue[5];
int capSense[5];
int ledPins[5];

void setup() {

  // Servo Setup
  Servo armServo;
  Servo headServo;
  armServo.attach(6); // Pin 6
  headServo.attach(3); // Pin 3
  int servoTarget = 0;
  /* servoTarget Values (for armServo):
   * 0 = Shoulder Rotator
   * 1 = Shoulder Raise
   * 2 = Elbow
   * etc: undefined
   * 
   */

  // Pin references for LED Output
 /* int ledPins[5];
  ledPins[0] = 5;
  ledPins[1] = 9;
  ledPins[2] = 10;
  ledPins[3] = 11;
  ledPins[4] = 13;
  for (int i = 0; i<5;i++) {
    pinMode(ledPins[i],OUTPUT);  
  */

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

  // Set up pin I/O, init capValue[]
  for (int i=0;i<5;i++) { 
    capValue[i] = 0;
    pinMode(capSense[i], INPUT);
    pinMode(ledPins[i], OUTPUT);
  }

  // Default Serial Value (9600)
  Serial.begin(9600);
  }

void loop() {

  // Trigger LEDs with Capacitor Touch Values
  for (int i=0;i<5;i++) {
    capValue[i] = digitalRead(capSense[i]);
    if (capValue[i] != 0) {
      digitalWrite(ledPins[i], LOW); 
      Serial.print("on"); 
    } else {
      digitalWrite(ledPins[i], HIGH);
    }
  }

}

