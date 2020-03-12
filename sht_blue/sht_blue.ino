#include <SHT1x.h>
#define dataPin 4
#define clockPin 3
SHT1x sht1x(dataPin, clockPin);
void setup() {
  Serial.begin(9600);
}

void loop() {
  float temp;
  float lembab;
  temp = sht1x.readTemperatureC();
  Serial.print("Suhu: ");
  Serial.print(temp);
  Serial.println(" C");
  delay(1000);
}
