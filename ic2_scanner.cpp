// --------------------------------------
// i2c_scanner
//
// Note we are expecting to see the ...
//  MPU9255 at 0x68
//  BMP-280 at 0x76
//  
//use IIC2
//TwoWire WIRE2 (2,I2C_FAST_MODE);
//#define Wire WIRE2

#include "ic2_scanner.h"
#include <Wire.h>
#include <Adafruit_BMP280.h> //include the Adafruit BMP280 library
#include <MPU9250.h>


void ic2_scanner() {
  byte error, address;
  int nDevices;

  Serial.println("Scanning for ic2 devices...");

  nDevices = 0;
  for(address = 1; address < 127; address++) {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.

    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) 
        Serial.print("0");
      Serial.println(address, HEX);

      nDevices++;
    }
    else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) 
        Serial.print("0");
      Serial.println(address, HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found");
  else
    Serial.println("Scan complete.");
}
