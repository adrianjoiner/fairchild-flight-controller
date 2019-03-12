#include "ic2_scanner.h"
#include "Arduino.h"
#include <Wire.h>

void setup() {  
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  delay(2000);

  ic2_scanner();

  

}

void loop() {
  // put your main code here, to run repeatedly:

}
