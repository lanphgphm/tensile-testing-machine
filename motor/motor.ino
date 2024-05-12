#include<AccelStepper.h> 
const int BUTTON_PIN = 7;
const int STEP_PIN = 2; 
const int DIR_PIN = 3;
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN); 


void setup(){
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
  stepper.setMaxSpeed(4000); 
  Serial.begin(9600);  
}

void loop(){
  int pinState = digitalRead(BUTTON_PIN); 
  Serial.println(pinState); 

  int sign = (pinState==HIGH) ? -1 : 1; // closer if LOW 
  Serial.println(pinState); 
  
  stepper.setSpeed(sign * 200); 
  stepper.runSpeed(); 
}
