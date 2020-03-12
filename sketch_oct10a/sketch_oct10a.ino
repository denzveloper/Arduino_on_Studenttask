int segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
byte digits[10][8] = { 
  //  a  b  c  d  e  f  g  . 
  { 1, 1, 1, 1, 1, 1, 0, 0},  // 0 
  { 0, 1, 1, 0, 0, 0, 0, 0},  // 1 
  { 1, 1, 0, 1, 1, 0, 1, 0},  // 2 
  { 1, 1, 1, 1, 0, 0, 1, 0},  // 3 
  { 0, 1, 1, 0, 0, 1, 1, 0},  // 4 
  { 1, 0, 1, 1, 0, 1, 1, 0},  // 5 
  { 1, 0, 1, 1, 1, 1, 1, 0},  // 6 
  { 1, 1, 1, 0, 0, 0, 0, 0},  // 7 
  { 1, 1, 1, 1, 1, 1, 1, 0},  // 8  
  { 1, 1, 1, 1, 0, 1, 1, 0}  // 9  
  };

void setup() {
  // put your setup code here, to run once:
  for (int i=0; i < 8; i++) { 
    pinMode(segmentPins[i], OUTPUT); 
  }
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int a=0; a<10; a++)
  { setSegments(a); delay(1000);Serial.println(a);
    }
  
}

void setSegments(int n) { 
  for (int i=0; i < 8; i++) { 
  digitalWrite(segmentPins[i], !digits[n][i]); } //kalau menggunakan common anoda gunakan ! (not)
  }

