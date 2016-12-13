int val;

void setup() {
  // 디지털 8번 핀에 연결
  pinMode(2, INPUT_PULLUP);
  // 시리얼 통신 초기화
  Serial.begin(9600);
}

void loop() {
  //2번 핀에서 데이터를 읽어들임
  val = digitalRead(2);
  // 시리얼 모니터로 데이터 출력
  Serial.println(val);
  delay(100);
}
