#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

// pin definition for the Uno
#define cs   10
#define dc   9
#define rst  8

// pin definition for the Leonardo
// #define cs   7
// #define dc   0
// #define rst  1

// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);

// char array to print to the screen
char printMoney[6];

void setup() {

  // Put this line at the beginning of every sketch that uses the GLCD:
  TFTscreen.begin();

  TFTscreen.background(0, 0, 0);    // 배경 검정색으로 설정

}

void loop() {
  int savings = 0;
  money(savings);

//  erase the text 
//  TFTscreen.stroke(0, 0, 0);
//  TFTscreen.text(sensorPrintout, 0, 20);
}






void money(int savings) {       // 현재 저장 금액 출력 함수
  
  String value = String(savings);

  value.toCharArray(printMoney, 6);

  TFTscreen.stroke(255, 255, 255);    // 폰트 색상 설정 (흰색)
  TFTscreen.setTextSize(2);           // 텍스트 사이즈 설정
  TFTscreen.text("Current Savings \n ", 0, 0);        // text(text, x좌표, y좌표) 
  TFTscreen.setTextSize(5);           // 텍스트 사이즈 설정
  TFTscreen.text(printMoney, 0, 20);  // 출력
  delay(250);

}







