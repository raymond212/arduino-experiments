#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 6

const int totalStates = 9;
int ledState[totalStates] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
int ledColor[totalStates] = {1, 2, 3, 1, 2, 3, 1, 2, 3}; 
int ledDuration[totalStates] = {200, 400, 500, 100, 200, 500, 500, 200, 300};

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < totalStates; i++) {
    int pin;
    if (ledColor[i] == 1) {
      pin = RED_PIN;
    } else if (ledColor[i] == 2) {
      pin = GREEN_PIN;
    } else{
      pin = BLUE_PIN;
    }
    digitalWrite(pin, ledState[i]);
    delay(ledDuration[i]);
    digitalWrite(pin, !ledState[i]);
  }
}
