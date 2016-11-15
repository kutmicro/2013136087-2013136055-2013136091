#include <Keypad.h>
#include <Servo.h> //s
 
Servo s; //s
//int servoPin = 11; //s
int min_value = 544; //s
int max_value = 2400; //s

char secretCode[4] = {'0', '0', '0', '0'};
char input[4];
char key;
int position = 0;
int wrong = 0;
int i = 0;
int j = 0;
int a = 0;
int pos = 0;
boolean c = false;




const byte numRows= 4;
const byte numCols= 4;

char keymap[numRows][numCols]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {8, 7, 6, 5}; 
byte colPins[numCols] = {4, 3, 2, 1}; 


Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup()
{
//Serial.begin(9600);
  Serial.begin(9600);
  //Serial.println("Servo Value = ");
  //s.attach(servoPin, min_value, max_value);
  s.attach(10);
  s.write(90);
  pinMode(10,INPUT);
}

void loop()
{
  while(a==0)
  {
    password_key();
    input_key();
    password();
    password_check();
  }
  if(a == 1)
  {
    pinMode(10, OUTPUT);
    s.write(180);
    delay(2000);
    key = myKeypad.waitForKey();
    if( key == '*')
    {
      s.write(90);
      delay(2000);
    }
  }
}

void password_key()
{
  for( i = 0 ; i <4 ; i++)
  {
    key = myKeypad.waitForKey();
    secretCode[i] = key;
    Serial.print(secretCode[i],DEC);
    Serial.print("*");
    if( i==3)
    {
      Serial.println("");
    }
  }
}

void input_key()
{
  for( i = 0 ; i <4 ; i++)
  {
    key = myKeypad.waitForKey();
    input[i] = key;
    Serial.print(input[i],DEC);
    Serial.print("*");
    if( i==3)
    {
      Serial.println("");
    }
  }
}

void password()
{
  wrong = 0;
  for( j = 0 ; j < 4 ; j++ )
  {
    if(secretCode[j] == input[j])
    {
    }
    else if(secretCode[j] != input[j])
    {
      wrong += 1;
    }
  }
}

void password_check()
{
  if(wrong == 0 )
  {
    Serial.println("correct");
    a=1;
  }
  else if( wrong != 0)
  {
    Serial.println("wrong");
    a=0;
    wrong=0;
  }
}


/*ar keypressed = myKeypad.getKey();
if (keypressed != NO_KEY)
{
  if(Serial.available() > 0 ) {
    int servo_value = Serial.parseInt();
    s.write(servo_value);
    Serial.println(servo_value);
  } 
  
}*/
//}

/*void loop() {
  if(Serial.available() > 0 ) {
    int servo_value = Serial.parseInt();
    s.write(servo_value);
    Serial.println(servo_value);
  }
}*/
