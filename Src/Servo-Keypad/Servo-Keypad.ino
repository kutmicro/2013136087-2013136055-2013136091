#include <Keypad.h>
#include <Servo.h> //s
#include "U8glib.h"
 
U8GLIB_NHD_C12864 u8g(13, 11, 10, 9, 8);    // SPI Com: SCK = 13, MOSI = 11, CS = 10, CD = 9, RST = 8

Servo s; //s
//int servoPin = 11; //s
int min_value = 544; //s
int max_value = 2400; //s
int saving = 0;   // 저금 금액
int goal = 30000;  // 목표 금액
int sensor0 = A8;  // 아날로그의 0번 핀 연결  
int sensor1 = A9;  // 아날로그의 0번 핀 연결
int sensor2 = A10;  // 아날로그의 0번 핀 연결
int sensor3 = A11;  // 아날로그의 0번 핀 연결

int speakerpin = 34; //스피커가 연결된 디지털핀 설정
int note[] = {2093,2349,2637,2793,3136,3520,3951,4186}; //도레미파솔라시도

char Password[4] = {'0', '0', '0', '0'};  // 설정된 패스워드 저장 배열 
char input[4];  // 입력된 패스워드 저장 배열
char key;   // 입력되는 키값 임시저장 변수                                    
//int position = 0;
int check = 0;   // 패스워드가 맞는지 체크하는 변수 
int ServoSignal = 0;
//int pos = 0;

const byte numROWS = 4; // 행
const byte numCOLS = 3; // 열

//2차원배열을 통해 키패드를 구현
char keymap[numROWS][numCOLS] = 
{ 
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[numROWS] = {22, 24, 6, 5}; //connect to the column pinouts of the keypad
byte colPins[numCOLS] = {26, 3, 28}; //connect to the column pinouts of the keypad

Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numROWS, numCOLS);

void setup() 
{
  Serial.begin(9600);
  u8g.setFont(u8g_font_unifont);
  u8g.setColorIndex(1);
  s.attach(12);
  s.write(180);
  pinMode(10,INPUT);
}

void loop() 
{
  u8g.firstPage();
  do {
    drawMain();
  } while(u8g.nextPage());
  delay(10);

  int reading0 = analogRead(sensor0);   // 아날로그 0번 핀에서 0~5V 사이로 변하는 값을 0~1023 사이의 값으로 읽는다
  float sensorV0 = reading0 * 5.0 / 1024.0; // 받아들인 값을 전압값(V)으로 변환 시킨다
  int sensormV0 = sensorV0 * 1000;          // 전압값을 단위를 mV로 변환시킨다.

  int reading1 = analogRead(sensor1);   // 아날로그 0번 핀에서 0~5V 사이로 변하는 값을 0~1023 사이의 값으로 읽는다
  float sensorV1 = reading1 * 5.0 / 1024.0; // 받아들인 값을 전압값(V)으로 변환 시킨다
  int sensormV1 = sensorV1 * 1000;          // 전압값을 단위를 mV로 변환시킨다.

  int reading2 = analogRead(sensor2);   // 아날로그 0번 핀에서 0~5V 사이로 변하는 값을 0~1023 사이의 값으로 읽는다
  float sensorV2 = reading2 * 5.0 / 1024.0; // 받아들인 값을 전압값(V)으로 변환 시킨다
  int sensormV2 = sensorV2 * 1000;          // 전압값을 단위를 mV로 변환시킨다.

  int reading3 = analogRead(sensor3);   // 아날로그 0번 핀에서 0~5V 사이로 변하는 값을 0~1023 사이의 값으로 읽는다
  float sensorV3 = reading3 * 5.0 / 1024.0; // 받아들인 값을 전압값(V)으로 변환 시킨다
  int sensormV3 = sensorV3 * 1000;          // 전압값을 단위를 mV로 변환시킨다.

  if( sensormV0 <= 1000) {
    insert500();
    delay(1000);
  }

  else if( sensormV1 <= 1000) {
    insert100();
    delay(1000);
  }

  else if( sensormV2 <= 1000) {
    insert50();
    delay(1000);
  }

  else if( sensormV3 <= 1000) {
    insert10();
    delay(1000);
  }
  
  
  key = myKeypad.getKey();
  if(key == '*') {
    u8g.firstPage();
    do {
      drawAstro0();
    } while(u8g.nextPage());
    delay(10);
    password_key();
    input_key();
    check_key();
  }
  
  if(ServoSignal == 1) {
    servo_act();
  }
}

void password_key()   // 패스워드 설정 함수
{     
  for(int i = 0 ; i <4 ; i++)
  {
    key = myKeypad.waitForKey();
    if(i == 0) {
      u8g.firstPage();
      do {
        drawAstro1();
      } while(u8g.nextPage());
      delay(10);
    }
    else if(i == 1) {
      u8g.firstPage();
      do {
        drawAstro2();
      } while(u8g.nextPage());
      delay(10);
    }
    else if(i == 2) {
      u8g.firstPage();
      do {
        drawAstro3();
      } while(u8g.nextPage());
      delay(10);
    }
    else {
      u8g.firstPage();
      do {
        drawAstro4();
      } while(u8g.nextPage());
      delay(10);
    }
    Password[i] = key;
  }
}

void input_key() // 패스워드 입력 함수
{      
  for(int i = 0 ; i <4 ; i++)
  {
    key = myKeypad.waitForKey();
    if(i == 0) {
      u8g.firstPage();
      do {
        drawAstro1();
      } while(u8g.nextPage());
      delay(10);
    }
    else if(i == 1) {
      u8g.firstPage();
      do {
        drawAstro2();
      } while(u8g.nextPage());
      delay(10);
    }
    else if(i == 2) {
      u8g.firstPage();
      do {
        drawAstro3();
      } while(u8g.nextPage());
      delay(10);
    }
    else {
      u8g.firstPage();
      do {
        drawAstro4();
      } while(u8g.nextPage());
      delay(10);
    }
    input[i] = key;
  }
}

void check_key() // 패스워드 비교 함수
{      
  // 비밀번호 비교
  for(int i = 0 ; i < 4 ; i++)
  {
    if(Password[i] == input[i])
    {
      check = 0;
    }
    else if(Password[i] != input[i])
    {
      check = 1;
      break;
    }
  }

  // 비밀번호 비교 후 서보모터로 해당하는 신호 보냄
  if(check == 0 ) {
    u8g.firstPage();
    do {
      drawCorrect();
    } while(u8g.nextPage());
    delay(1000);
    ServoSignal = 1;
    check = 1;
  }
  else {
    u8g.firstPage();
    do {
      drawWrong();
    } while(u8g.nextPage());
    delay(1000);
    ServoSignal = 0;
  }
}

void servo_act() // 서보모터 동작 함수
{    
  pinMode(10, OUTPUT);        // ( pin의 넘버, pin의 모드 ) 모드 => INPUT, OUTPUT, INPUT_PULLUP 
  s.write(90);
  delay(2000);
//  key = myKeypad.waitForKey();
//  if( key == '*') {
//    s.write(90);
//    delay(2000);
//    s.write(0);
//  }
  s.write(180);
  ServoSignal = 0;
}

void drawMain()   // Main
{ 
  char savingB[9];
  char goalB[9];
  u8g.setFont(u8g_font_unifont);
  sprintf(savingB, "%d", saving);
  sprintf(goalB, "%d", goal);
  u8g.drawStr(20, 40, savingB);
  u8g.drawStr(80, 40, goalB);
  u8g.drawStr(65, 40, "/" );
  u8g.drawStr(0, 20, " Current Saving" );
}

void drawAstro0() 
{    
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(10, 40, "PW : ");
}

void drawAstro1() 
{    
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(10, 40, "PW : *");
}

void drawAstro2() 
{    
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(10, 40, "PW : * *");
}

void drawAstro3() 
{    
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(10, 40, "PW : * * *");
}

void drawAstro4() 
{    
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(10, 40, "PW : * * * *");
}

void drawCorrect() 
{    
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(10, 40, "CORRECT!!");
}

void drawWrong() 
{    
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(10, 40, "WRONG!!");
}

void draw500() 
{    
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(10, 40, "500 WON");
}

void draw100() 
{    
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(10, 40, "100 WON");
}

void draw50() 
{    
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(10, 40, "50 WON");
}

void draw10() 
{    
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(10, 40, "10 WON");
}

void insert500()
{
  saving += 500;
  u8g.firstPage();
  do {
    draw500();
  } while(u8g.nextPage());
  music();
}

void insert100()
{
  saving += 100;
  u8g.firstPage();
  do {
    draw100();
  } while(u8g.nextPage());
  music();
}

void insert50()
{
  saving += 50;
  u8g.firstPage();
  do {
    draw50();
  } while(u8g.nextPage());
}

void insert10()
{
  saving += 10;
  u8g.firstPage();
  do {
    draw10();
  } while(u8g.nextPage());
}

void music() {
  int elementCount = sizeof(note) / sizeof(int);
  tone(speakerpin,note[0],500);
  delay(250);
  tone(speakerpin,note[2],250);
  delay(125);
  tone(speakerpin,note[4],500);
  delay(250);
  tone(speakerpin,note[2],250);
  delay(125);
  tone(speakerpin,note[4],500);
  delay(250);
}

