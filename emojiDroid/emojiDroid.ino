#include <Servo.h>

#define SERVO_A 7
#define SERVO_B 8 // Note: no semicolons in macro definitions

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
  int ledPins[5];
  ledPins[0] = 5;
  ledPins[1] = 9;
  ledPins[2] = 10;
  ledPins[3] = 11;
  ledPins[4] = 13;
  for (int i = 0; i<5;i++) {
    pinMode(ledPins[i],OUTPUT);  
  }

  // Capacitive input 
    // STUB

}

void loop() {
  // put your main code here, to run repeatedly:

}
