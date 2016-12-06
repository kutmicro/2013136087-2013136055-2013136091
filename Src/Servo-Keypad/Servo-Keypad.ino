#include <Keypad.h>
#include <Servo.h> //s
 
Servo s; //s
//int servoPin = 11; //s
int min_value = 544; //s
int max_value = 2400; //s

char Password[4] = {'0', '0', '0', '0'};  // 설정된 패스워드 저장 배열 
char input[4];  // 입력된 패스워드 저장 배열
char key;   // 입력되는 키값 임시저장 변수                                    
int position = 0;
int check = 0;   // 패스워드가 맞는지 체크하는 변수 
int ServoSignal = 0;
int pos = 0;

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
  s.attach(12);
  s.write(180);
  pinMode(10,INPUT);
}

void loop() 
{
  while(ServoSignal == 0) {
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
    Password[i] = key;
    Serial.print(Password[i],DEC);
    Serial.print("*");
  }
  Serial.println("");
}

void input_key() // 패스워드 입력 함수
{      
  for(int i = 0 ; i <4 ; i++)
  {
    key = myKeypad.waitForKey();
    input[i] = key;
    Serial.print(input[i],DEC);
    Serial.print("*");
  }
  Serial.println("");
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
    Serial.println("correct");
    ServoSignal = 1;
    check = 1;
  }
  else {
    Serial.println("wrong");
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


