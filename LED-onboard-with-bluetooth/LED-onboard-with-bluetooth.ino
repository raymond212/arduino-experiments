#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);

// Remember to wire bluetooth RXD to 11 and TXD to 10

void setup() {
  pinMode(13, OUTPUT);
  BT.begin(9600);
  BT.println("Hello from Arduino");
}

void loop() {
  if (BT.available()) {
    char a = BT.read();
    if (a == '1') {
      digitalWrite(13, HIGH);
      BT.println("LED on");
    }
    if (a == '2') {
      digitalWrite(13, LOW);
      BT.println("LED off");
    }
    if (a == '?') {
      BT.println("Send '1' to turn LED on");
      BT.println("Send '2' to turn LED off");
    }
  }
}
