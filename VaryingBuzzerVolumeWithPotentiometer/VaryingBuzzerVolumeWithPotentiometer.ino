#define BUZZER_PIN 8

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  tone(BUZZER_PIN, 440);
}

void loop() {
}
