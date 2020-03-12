#define trigPin 13
#define echoPin 12
#include <Servo.h> 
Servo myservo;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(10);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance <= 5) {
    myservo.write(45);
    Serial.print(distance);
    Serial.println(" cm");
  }
  else if (distance <=20) {
    myservo.write(90);
    Serial.print(distance);
    Serial.println(" cm");
  }
  else if (distance <=50) {
    myservo.write(135);
    Serial.print(distance);
    Serial.println(" cm");
  }
  else if (distance <=40) {
    myservo.write(180);
    Serial.print(distance);
    Serial.println(" cm");
  }
  else{
    myservo.write(10);
    Serial.println("Out Of Range!");
  }
  delay(1000);
}

