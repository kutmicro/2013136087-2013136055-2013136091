int sensor = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(sensor);
  float sensorV = reading * 5.0 / 1024.0;
  int sensormV = sensorV * 1000;
  Serial.println(sensormV);
  delay(500);
}


