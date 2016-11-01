int speakerpin = 12; //스피커가 연결된 디지털핀 설정
int note[] = {2093,2349,2637,2793,3136,3520,3951,4186}; //도레미파솔라시도
 
void setup() {
  int elementCount = sizeof(note) / sizeof(int);
  tone(speakerpin,note[0],500);
  delay(500);
  tone(speakerpin,note[2],250);
  delay(250);
  tone(speakerpin,note[4],500);
  delay(500);
  tone(speakerpin,note[2],250);
  delay(250);
  tone(speakerpin,note[4],500);
  delay(500);
}
 
void loop() {
}
