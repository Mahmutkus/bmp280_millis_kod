#include <Wire.h>
#include <Adafruit_BMP280.h>
#include "I2Cdev.h" //I2C kütüphanesi
Adafruit_BMP280 bmp; 

unsigned long SimdikiZaman = 0;
unsigned long OncekiZaman = 0;
int aralik = 999;

void setup()
{
  Serial.begin(9600);
  bmp.begin();
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */ /* MODE_FORCED */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */ /* SAMPLING_X2 , SAMPLING_X16 */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_125); /* Standby time. */ /* STANDBY_MS_1 , STANDBY_MS_63 , STANDBY_MS_125 , STANDBY_MS_250 , STANDBY_MS_500*/
}

void loop() {
  SimdikiZaman = millis();
  if  (SimdikiZaman - OncekiZaman > aralik)
  {
    OncekiZaman = SimdikiZaman;
    Serial.print(F("Temperature = "));        Serial.print(bmp.readTemperature());       Serial.println(" *C");

    Serial.print(F("Pressure = "));           Serial.print(bmp.readPressure() / 100);    Serial.println(" hPa");

    Serial.print(F("Approx altitude = "));    Serial.print(bmp.readAltitude(657.18));    Serial.println(" m");

  }
}
