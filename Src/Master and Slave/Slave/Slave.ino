#include <Wire.h> 
void setup()
{
  Wire.begin(4);                
  Wire.onReceive(receiveEvent); 
  Serial.begin(9600);        
}
 
void loop()
{
  String test = "slave";
  wireSend(test);         // 1초마다 전송
  delay(1000);
}


/************************************
 * Wire 통신 관련 기능
 *************************************/
// Wire 데이터 전송
void wireSend(String tmp){
  Wire.beginTransmission(4);
  Wire.write(tmp.c_str());
  Wire.endTransmission();
}

// 마스터 아두이노에서 받은 데이터 처리
void receiveEvent(int howMany)
{
  Serial.println("receive Y");
  String tmpStr = "";
  while(Wire.available()){
    //Serial.println(Wire.read());
    char c = Wire.read();
    //Serial.print(c);
    tmpStr = tmpStr + c;
  }
  Serial.println(tmpStr);
}
