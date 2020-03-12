#include <Keypad.h>
char* secretCode = "3333"; 
int position = 0;
const byte rows = 4; 
const byte cols = 3; 
char keys[rows][cols] = { 
  {'1','2','3'}, 
  {'4','5','6'}, 
  {'7','8','9'}, 
  {'*','0','#'} }; 
 byte rowPins[rows] = {4,5,6,7}; 
 byte colPins[cols] = {8, 2, 3}; 
 Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);
int redPin = 10; int greenPin = 9;
void setup() { 
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  Serial.begin(9600);
  setLocked(true); }
void loop() { 
  char key = keypad.getKey(); 
  Serial.print(key);
  if (key == '*' || key == '#') { 
    position = 0; setLocked(true); } 
  if (key == secretCode[position]) { position ++; } 
  if (position == 4) { 
    setLocked(false); } delay(100); }
  
void setLocked(int locked)
{
if (locked) { 
  digitalWrite(redPin, HIGH); 
  digitalWrite(greenPin, LOW); 
  Serial.println("tutup");} 
  else { 
    digitalWrite(redPin, LOW); 
  digitalWrite(greenPin, HIGH);
  Serial.println("Terbuka!");}
}

