int sensor = A0;  // 아날로그의 0번 핀 연결

void setup() {
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(sensor);   // 아날로그 0번 핀에서 0~5V 사이로 변하는 값을 0~1023 사이의 값으로 읽는다
  float sensorV = reading * 5.0 / 1024.0; // 받아들인 값을 전압값(V)으로 변환 시킨다
  int sensormV = sensorV * 1000;          // 전압값을 단위를 mV로 변환시킨다.
  Serial.println(sensormV);
  delay(500);
}


