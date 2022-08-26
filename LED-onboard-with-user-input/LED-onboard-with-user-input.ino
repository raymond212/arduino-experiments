void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.println("LED is ready");
}

void loop() {
  if (Serial.available()) {
    char z = Serial.read();
    if (z == 'o' || z == 'O') {
      digitalWrite(13, HIGH);
    }
    if (z == 'f' || z == 'F') {
      digitalWrite(13, LOW);
    }
  }
}
