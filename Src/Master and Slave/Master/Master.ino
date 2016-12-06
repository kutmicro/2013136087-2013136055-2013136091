#include <Wire.h>

#define Slave 0x04
 
void setup()
{
  Serial.begin(9600);
  Wire.begin();
}
 
void loop()
{
  Wire.beginTransmission(Slave);
  Wire.write(1);
  Serial.println('1');
  Wire.endTransmission();
  delay(1000);

  Wire.beginTransmission(Slave);
  Wire.write(2);
  Serial.println('2');
  Wire.endTransmission();
  delay(1000);
}
