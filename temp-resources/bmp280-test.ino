#include <Wire.h>

// https://www.weatheronline.co.uk/weather/maps/current?LANG=en&CONT=euro&REGION=0003&LAND=NL&LEVEL=4&R=310&CEL=C&ART=tabelle&TYP=druck
/***************************************************************************
  This is a demo of the BMP280 humidity, temperature & pressure sensor
  for the O Watch. http://theowatch.com 
  Made on products from http://tiny-circuits.com
  Derived from the BMP280 library  test program by Adafruit 
  ----> http://www.adafruit.com/products/2651

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing products
  from Adafruit!

  Original library and example written by Limor Fried & Kevin Townsend for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution

 ***************************************************************************/

#include <Adafruit_BMP280.h> //include the Adafruit BMP280 library

//Initialize the library using I2C 
Adafruit_BMP280 bme; // I2C is the interface used in TinyScreen+ for all sensors

void setup() 
{
  Serial.begin(9600);
  delay(2000);
  Serial.println("Opnening serial port");
  Wire.begin();
  Wire.setClock(400000); //Increase to fast I2C speed!
  delay(1000);
  ic2_scan();


 
  

  // Check sensor can be read
  // Note the override for the address of the BMP280 - default is0x77 but ours is 0x76
  if (!bme.begin(0x76)) //check if you are able to read the sensor
  {  
    Serial.println("Not valid BMP280");
    while (1);
  }
  
}

void loop() {
    //call library function to reach temp value and converting it to farenheit
    
    Serial.print("Temperatue: ");
    Serial.println(bme.readTemperature()); // in celsius

    //call library function to reach pressure value
    Serial.print(bme.readPressure()/3389.39); 
    Serial.println(" inHg.");
    
    Serial.print("Alt = ");
    //call library function to calculate altitude from pressure
    Serial.print(bme.readAltitude(997)+10); // this should be adjusted to your local forcase
    Serial.println(" m  ");
    
    delay(5000);
    
}

void ic2_scan() {
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

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
    Serial.println("done");

}