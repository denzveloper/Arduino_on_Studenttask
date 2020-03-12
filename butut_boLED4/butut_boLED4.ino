char blueToothVal;
char lastValue;
void setup(){
Serial.begin(9600);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
}
void loop(){
if(Serial.available()){    
  blueToothVal=Serial.read();
}
if (blueToothVal=='1'){    
  digitalWrite(8,HIGH);            
  //switch on LED    
  if (lastValue!='n')      
  Serial.println(F("LED 1 is on"));
  lastValue=blueToothVal;
}
else if (blueToothVal=='2'){   
  digitalWrite(9,HIGH);  
  if (lastValue!='f')     
    Serial.println(F("LED 2 is on"));
  lastValue=blueToothVal;
}
else if (blueToothVal=='3'){   
  digitalWrite(10,HIGH);  
  if (lastValue!='f')     
    Serial.println(F("LED 3 is on"));
  lastValue=blueToothVal;
}
else if (blueToothVal=='4'){   
  digitalWrite(11,HIGH);  
  if (lastValue!='f')     
    Serial.println(F("LED 4 is on"));
  lastValue=blueToothVal;
}
else if (blueToothVal=='a'){   
  digitalWrite(8,LOW);  
  if (lastValue!='f')     
    Serial.println(F("LED 1 is off"));
  lastValue=blueToothVal;
}
else if (blueToothVal=='b'){   
  digitalWrite(9,LOW);  
  if (lastValue!='f')     
    Serial.println(F("LED 2 is off"));
  lastValue=blueToothVal;
}
else if (blueToothVal=='c'){   
  digitalWrite(10,LOW);  
  if (lastValue!='f')     
    Serial.println(F("LED 3 is off"));
  lastValue=blueToothVal;
}
else if (blueToothVal=='d'){   
  digitalWrite(11,LOW);  
  if (lastValue!='f')     
    Serial.println(F("LED 4 is off"));
  lastValue=blueToothVal;
}
delay(1000);}

