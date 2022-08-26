#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);

void setup() {
  pinMode(13, OUTPUT);
  BT.begin(9600);
  BT.println("Started");
}

void loop() {
  if (BT.available() > 0) {
    char val = BT.read();
    if (val == '1') {
      digitalWrite(13, HIGH);
    } else if (val == '0') {
      digitalWrite(13, LOW);
    }
  }
}


// Wire bluetooth RXD to 1 and TXD to 0
// SoftwareSerial is better than directly wiring to TX and RX

//void setup() {
//  pinMode(13, OUTPUT);
//  Serial.begin(9600);
//  Serial.println("Started");
//}
//
//void loop() {
//  if (Serial.available()) {
//    int state = Serial.read();
//    Serial.println(state);
//    if (state == 1) {
//      digitalWrite(13, HIGH);
//    } 
//    if (state == 0) {
//      digitalWrite(13, LOW);
//    }
//  }
//}
