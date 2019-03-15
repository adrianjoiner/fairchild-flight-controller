#include "ic2_scan.ino"
#include "Arduino.h"
#include <Wire.h>

// global constants
const byte BMP280_address=0x76;
const byte MPU9250_address=0x68;

void setup() {  
 
  // Open a serial port for debug and printing
  Serial.begin(9600);

  // Initialise the wire library
  Wire.begin();
  Wire.setClock(400000); //Increase to fast I2C speed!
  delay(2000);

  // scan for connected sensors, epecting to see ...
  //    MPU9255 at 0x68
  //    BMP-280 at 0x76
  // Check for any connected sensors
  ic2_scan();

  // Initialise the BMP280 barometer (altitude sensor)
  Adafruit_BMP280 barometer;
  if (!barometer.begin(BMP280_ADDRESS)) //check if you are able to read the sensor
  {  
    Serial.println("SENSOR: barometer not found, no further tests will be made on this sensor.");
    while (1);
  }
  
  // Display current output of the barometer
  // Temperature
  Serial.print("Temperatue: ");
  Serial.println(barometer.readTemperature()); // in celsius
  
  // Pressure
  Serial.print(barometer.readPressure()/3389.39); 
  Serial.println(" inHg.");

  // Altitude
  Serial.print("Alt = ");
  Serial.print(barometer.readAltitude(997)+10); // this should be adjusted to your local forcase
  Serial.println(" m  ");

   

}

void loop() {
  // put your main code here, to run repeatedly:

}