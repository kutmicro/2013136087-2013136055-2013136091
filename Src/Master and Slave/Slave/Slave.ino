#include <Wire.h>
 
void setup()
{
  Wire.begin(4); // Slave 4번 핀에 연결
  Wire.onReceive(receiveEvent); // 데이터를 받았을때 함수 실행
  Serial.begin(9600);
}
 
void loop()
{
  String test = "master";
  wireSend(test);         // 1초마다 전송
  delay(1000);
}

/************************************
 * Wire 통신 관련 기능
 *************************************/

void wireSend(String tmp){ // // Wire 데이터 전송
  Wire.beginTransmission(4); // 4번 핀에 데이터 전송
  Wire.write(tmp.c_str()); // byte형 데이터를 통신
  Wire.endTransmission(); // 통신을 끝냄
}
void receiveEvent(int howMany) // Wire 데이터를 받았을때
{
  Serial.println("receive"); // receive 출력
  String tmpStr = "";
  while(Wire.available()){ // 읽어올 데이터가 버퍼에 남아있으면
    //Serial.println(Wire.read());
    char c = Wire.read(); // 데이터를 읽고 c에 저장
    //Serial.print(c);
    tmpStr = tmpStr + c;
  }
  Serial.println(tmpStr);
}#include <Wire.h>
 
void setup()
{
  Wire.begin(4); // Slave 4번 핀에 연결
  Wire.onReceive(receiveEvent); // 데이터를 받았을때 함수 실행
  Serial.begin(9600);
}
 
void loop()
{
  String test = "master";
  wireSend(test);         // 1초마다 전송
  delay(1000);
}

/************************************
 * Wire 통신 관련 기능
 *************************************/

void wireSend(String tmp){ // // Wire 데이터 전송
  Wire.beginTransmission(4); // 4번 핀에 데이터 전송
  Wire.write(tmp.c_str()); // byte형 데이터를 통신
  Wire.endTransmission(); // 통신을 끝냄
}
void receiveEvent(int howMany) // Wire 데이터를 받았을때
{
  Serial.println("receive"); // receive 출력
  String tmpStr = "";
  while(Wire.available()){ // 읽어올 데이터가 버퍼에 남아있으면
    //Serial.println(Wire.read());
    char c = Wire.read(); // 데이터를 읽고 c에 저장
    //Serial.print(c);
    tmpStr = tmpStr + c;
  }
  Serial.println(tmpStr);
}
