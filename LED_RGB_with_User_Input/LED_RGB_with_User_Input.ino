#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 6

const int steps = 5;
int ledState[steps];
int ledColor[steps]; 

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  
  Serial.print("Number of steps in pattern: ");
  Serial.println(steps);
  
  for (int i = 0; i < steps; i++) {
    Serial.print("State of step ");
    Serial.print(i + 1);
    Serial.print(": ");
    while (Serial.available() == 0) {
    }    
    int state = Serial.parseInt();
    Serial.println(state);
    Serial.print("Color of step ");
    Serial.print(i + 1);
    Serial.print(": ");
    while (Serial.available() == 0) {
    }
    int color = Serial.parseInt();
    Serial.println(color);
    ledState[i] = state;
    ledColor[i] = color;  
  }
}

void loop() {
  for (int i = 0; i < steps; i++) {
    int pin;
    if (ledColor[i] == 1) {
      pin = RED_PIN;
    } else if (ledColor[i] == 2) {
      pin = GREEN_PIN;
    } else{
      pin = BLUE_PIN;
    }
    digitalWrite(pin, ledState[i]);
    delay(500);
    digitalWrite(pin, !ledState[i]);
  }
}
