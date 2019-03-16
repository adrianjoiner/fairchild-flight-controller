#include "ic2_scanner.h"
#include "Arduino.h"
#include <Wire.h>

// global constants
byte BMP280_address=0x76;
byte MPU9250_address=0x68;

void setup() {  
 
  // Open a serial port for debug
  Serial.begin(9600);

  // Initialise the wire library
  Wire.begin();
  Wire.setClock(400000); //Increase to fast I2C speed!
  delay(2000);

  // scan for connected sensors, epecting to see ...
  //    MPU9255 at 0x68
  //    BMP-280 at 0x76
  ic2_scanner();

  



  

}

void loop() {
  // put your main code here, to run repeatedly:

}
