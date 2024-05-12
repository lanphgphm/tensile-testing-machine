#include <Arduino.h>
#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 4;
const int LOADCELL_SCK_PIN = 5;

HX711 scale;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing the scale");

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  Serial.println("Before setting up the scale:");
  Serial.print("read: \t\t");
  Serial.println(scale.read());     

  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(20));   

  Serial.print("get value: \t\t");
  Serial.println(scale.get_value(5));  

  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1);  
            
  scale.set_scale(-43748.73911); // this number is the result of linear regression 
  scale.tare();               
}

void loop() {
  Serial.print("force:\t");
  Serial.println(scale.get_units(10), 5);

  delay(500);
}
