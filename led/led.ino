int leda=9;
int ledb=10;
int ledc=11;
int ledd=12;
int set=0;
void setup() {
  Serial.begin(9600);
  pinMode(leda,OUTPUT);
  pinMode(ledb,OUTPUT);
  pinMode(ledc,OUTPUT);
  pinMode(ledd,OUTPUT);
}

void loop() {
  set = Serial.read();
  if(set == 97){
    setlam(HIGH,LOW,LOW,LOW);
  }
  if(set == 98){
    setlam(LOW,HIGH,LOW,LOW);
  }
  if(set == 99){
    setlam(LOW,LOW,HIGH,LOW);
  }
  if(set == 100){
    setlam(LOW,LOW,LOW,HIGH);
  }
  if(set == 101){
    setlam(HIGH,LOW,LOW,LOW);
  }
  if(set == 102){
    setlam(HIGH,HIGH,HIGH,HIGH);
  }
}

void setlam(int one, int two, int three, int four){
  digitalWrite(leda,one);
  digitalWrite(ledb,two);
  digitalWrite(ledc,three);
  digitalWrite(ledd,four);
}

