
//
// Scans the ic2 bus and prints the address of any attached sensors
//

#include <Wire.h>
#include <Adafruit_BMP280.h> //include the Adafruit BMP280 library
#include <MPU9250.h>


void ic2_scan() {
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
