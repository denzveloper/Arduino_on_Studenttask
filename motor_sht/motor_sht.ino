#include <SHT1x.h>
const int motor1  = 5;
const int motor2  = 4;
#define dataPin 10
#define clockPin 11
SHT1x sht1x(dataPin, clockPin);

void setup(){
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  Serial.begin(9600);
}

void loop(){
float suhu;
float kelembaban;
suhu = sht1x.readTemperatureC();
kelembaban = sht1x.readHumidity();
Serial.print("Suhu: ");
Serial.println(suhu);
//Serial.print("Kelembapan: ");
//Serial.print(kelembaban);
//Serial.println(" %");
if (suhu > 30) {
analogWrite(motor1, 180);
analogWrite(motor2, 0);
}
else if (suhu = 30) {
analogWrite(motor1, 0);
analogWrite(motor2, 0);
}
else if (suhu < 27) {
analogWrite(motor1, 0);
analogWrite(motor2, 360);
}
else{
  analogWrite(motor1, 360);
  analogWrite(motor2, 360);
}
delay(500);
}
