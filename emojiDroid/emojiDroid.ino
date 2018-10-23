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
 /* int ledPins[5];
  ledPins[0] = 5;
  ledPins[1] = 9;
  ledPins[2] = 10;
  ledPins[3] = 11;
  ledPins[4] = 13;
  for (int i = 0; i<5;i++) {
    pinMode(ledPins[i],OUTPUT);  
  */
  }
 int cp1,cp2,cp3,cp4,cp5 = 0;


int CapSense1 = 8;
int CapSense2= 9;
int CapSense3 =10;
int CapSense4 =11;
int CapSense5 =12;

int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED3 = 6;


void setup() {
 
  pinMode(CapSense1, INPUT);
  pinMode(CapSense2,INPUT);
  pinMode(CapSense3, INPUT);
  pinMode(CapSense4, INPUT);
  pinMode(CapSense5,INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {

   cp1 = digitalRead(CapSense1);
   cp2 = digitalRead(CapSense2);
   cp3 = digitalRead(CapSense3); 
   cp4 = digitalRead(CapSense4);
   cp5 = digitalRead(CapSense5); 
   

  if(cp1 != 0 ){
  digitalWrite(LED1, LOW); 
  Serial.print("on"); } 
  else
  digitalWrite(LED1, HIGH);


  if(cp2 != 0 ){
  digitalWrite(LED2, LOW); 
  Serial.print("on"); } 
  else
  digitalWrite(LED2, HIGH);

  if(cp3 != 0 ){
  digitalWrite(LED3, LOW); 
  Serial.print("on"); } 
  else
  digitalWrite(LED3, HIGH);

  if(cp4 != 0 ){
  digitalWrite(LED4, LOW); 
  Serial.print("on"); } 
  else
  digitalWrite(LE4, HIGH);

 if(cp5 != 0 ){
  digitalWrite(LED5, LOW); 
  Serial.print("on"); } 
  else
  digitalWrite(LED5, HIGH);

}
