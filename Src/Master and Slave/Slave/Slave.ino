#include <Wire.h>
 
boolean isOn = false;
 
void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);
}
 
void loop() {
  Wire.beginTransmission(8);    // send to address #8 (0x08)
  if(isOn) {
    Wire.write('1'); 
    Serial.print(1);
  }
  else {
    Wire.write('0'); 
    Serial.print(0);
  }
  Wire.endTransmission();  
 
  isOn = !isOn;
  delay(500);
}
