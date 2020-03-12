#include <SHT1x.h>
#define dataPin  11
#define clockPin 10
#define Relay  9
SHT1x sht1x(dataPin, clockPin);
 
void setup()
{
   Serial.begin(9600);
   pinMode(Relay, OUTPUT);  
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
  if(temp_c>29){
    digitalWrite(Relay,0);//Turn On Fan
  }
  else{
    digitalWrite(Relay,1);//Turn Off Fan
  }
  delay(500);
}
