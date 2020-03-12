#include <Servo.h> 
Servo myservo;
void setup(){
  myservo.attach(9);
}

void loop(){
  myservo.write(45);
  delay(2000);
  myservo.write(90);
  delay(100);
  myservo.write(135);
  delay(2000);
  myservo.write(90);
  delay(100);
  myservo.write(80);
  delay(2000);
  myservo.write(90);
  delay(100);
  myservo.write(100);
  delay(2000);
}

