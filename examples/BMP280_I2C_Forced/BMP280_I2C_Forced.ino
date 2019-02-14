///////////////////////////////////////////////////////////////////////////////
// BMP280 - I2C Communications, Default Configuration, Normal Conversion
///////////////////////////////////////////////////////////////////////////////

#include <BMP280.h>                               // Include the BMP280.h library

float temperature, pressure, altitude;            // Create the temperature, pressure and altitude variables
BMP280 bmp280;                                    // Instantiate (create) a BMP280 object and set-up for I2C operation (address 0x77)

void setup() 
{
  Serial.begin(115200);                           // Initialise the serial port
  bmp280.begin();                                 // Default initialisation, place the BMP280 into SLEEP_MODE 
  //bmp280.setPresOversampling(OVERSAMPLING_X4);    // Set the pressure oversampling to X4
  //bmp280.setTempOversampling(OVERSAMPLING_X1);    // Set the temperature oversampling to X1
  //bmp280.setIIRFilter(IIR_FILTER_4);              // Set the IIR filter to setting 4 
}

void loop() 
{
  bmp280.startForcedConversion();                 // Start BMP280 forced conversion (if we're in SLEEP_MODE)
  if (bmp280.getMeasurements(temperature, pressure, altitude))    // Check if the measurement is complete
  {
    Serial.print(temperature);                    // Display the results    
    Serial.print(F("*C   "));
    Serial.print(pressure);    
    Serial.print(F("hPa   "));
    Serial.print(altitude);
    Serial.println(F("m"));  
  }
}