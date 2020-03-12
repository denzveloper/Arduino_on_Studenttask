char blueToothVal;
char lastValue;
void setup(){
Serial.begin(9600);  
pinMode(8,OUTPUT);
}  
void loop(){
if(Serial.available()){    
  blueToothVal=Serial.read();
}
if (blueToothVal=='n'){    
  digitalWrite(8,HIGH);            
  //switch on LED    
  if (lastValue!='n')      
  Serial.println(F("LED is on"));
  lastValue=blueToothVal;
}
else if (blueToothVal=='f'){   
  digitalWrite(8,LOW);  
  if (lastValue!='f')     
    Serial.println(F("LED is off"));
  lastValue=blueToothVal;
}
delay(500);}

