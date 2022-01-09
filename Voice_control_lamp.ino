#include <SoftwareSerial.h>

SoftwareSerial BT(0, 1); //TX, RX respetively
String readvoice;

void setup() {
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(13, OUTPUT);
  
  
  
} 
void loop() {
  while (BT.available()){ 
  delay(10); 
  char c = BT.read(); 
  readvoice += c; 
  } 
  if (readvoice.length() > 0) {
    Serial.println(readvoice);

  if(readvoice == "*turn on light#")// Light will Turn on
  {
    digitalWrite(13,LOW);
    delay(100);
  }

  else if(readvoice == "*turn off light#") // Light will Turn off
  {
    digitalWrite(13,HIGH);
    delay(100);
  }
 
 readvoice="";}} //Reset the variable
 // disconnect RX and TX pin while uploading the program.//
