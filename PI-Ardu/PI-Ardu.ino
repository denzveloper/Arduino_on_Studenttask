#include <SHT1x.h>
 
// Specify data and clock connections and instantiate SHT1x object
#define dataPin  10
#define clockPin 11
SHT1x sht1x(dataPin, clockPin);
 
void setup()
{
   Serial.begin(9600);
}
void loop()
{
  float temp_c;
  float humidity;
 
  // Read values from the sensor
  temp_c = sht1x.readTemperatureC();
  humidity = sht1x.readHumidity();
 
  // Print the values to the serial port
  Serial.print(temp_c);
  Serial.print("\t");
  Serial.print(humidity);
  Serial.println("\t");
 
  delay(5000);
}
