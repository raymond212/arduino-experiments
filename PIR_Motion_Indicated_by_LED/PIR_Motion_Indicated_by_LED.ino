#define LED_PIN 4 
#define INPUT_PIN 3

int pirState = LOW;
int val = 0;

int calibrationTime = 30;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(INPUT_PIN, INPUT);
  Serial.begin(9600);
  Serial.println("Waiting for the sensor to warm up.");
//  delay(calibrationTime * 1000);
  Serial.println("SENSOR ACTIVE");
}

void loop() {
  val = digitalRead(INPUT_PIN);
  if (val == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {
    digitalWrite(LED_PIN, LOW);
    if (pirState == HIGH) {
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
  delay(1000);
}
