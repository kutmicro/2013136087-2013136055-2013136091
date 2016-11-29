#include <Keypad.h> //키패드를 명령어를 사용하기 위한 헤더파일 선언.

const byte ROWS = 4; // 행
const byte COLS = 3; // 열
char keys[ROWS][COLS] = { //2차원배열을 통해 키패드를 구현
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //키패드 클래스 객체선언.

void setup(){
  Serial.begin(9600);
}

void loop(){
  char key = keypad.getKey();

  if (key != NO_KEY){ //만약 키가 입력이 될경우
    Serial.println(key); //키를 화면에 출력
  }
}
