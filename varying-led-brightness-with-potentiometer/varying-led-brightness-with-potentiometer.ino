void setup() {
  pinMode(6, OUTPUT);
}

void loop() {
  int potValue = analogRead(A0);
  int mappedValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(6, mappedValue);
}
