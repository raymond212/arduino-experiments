#define LED_PIN 4

int ledState = LOW;
int sampleSpan = 200;
int threshold = 100;

int maxValue;
int minValue;
int volume;
unsigned long timer;


void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void resetValues() {
  maxValue = 0;
  minValue = 1024;
  timer = millis();
}

void loop() {
  int val = analogRead(A0);
  if (val < minValue) {
    minValue = val;
  }
  if (val > maxValue) {
    maxValue = val;
  }
  if (millis() - timer >= sampleSpan) {
    volume = maxValue - minValue;
    resetValues();
    if (volume > threshold) {
      Serial.print("SWITCH. LED: ");
      digitalWrite(LED_PIN, !ledState);
      ledState = !ledState;
      if (ledState == HIGH) {
        Serial.println("ON");
      } else {
        Serial.println("OFF");
      }
    }
  }
}
