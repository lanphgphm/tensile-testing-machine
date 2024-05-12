// Calibrating the load cell
// This code does not include writing data to a .csv file 
// You need to open Serial Monitor 
// and copy the output to a file manually
#include <HX711.h>

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 4;
const int LOADCELL_SCK_PIN = 5;

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  delay(500);
  scale.tare();
  delay(500);  
  Serial.println("Starting to record reading..."); 
}

void loop() {
  if (scale.is_ready()) {
    long reading = scale.get_units(20);
    Serial.print("Result: ");
    Serial.println(reading);
  } 
  else {
    Serial.println("HX711 not found.");
  }
  delay(100); // do NOT omit this, HX711 needs time to rest :) 
}
