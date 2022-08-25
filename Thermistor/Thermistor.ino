#include "thermistor.h"

#define SERIESRESISTOR 10070
#define THERMISTORPIN A0

THERMISTOR thermistor(THERMISTORPIN, // Analog pin
                      9000, // Resistance at 25 C
                      3950, // Thermistor's beta coefficient
                      SERIESRESISTOR); // Value of series resistor
                      
uint16_t temp;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // basic reading of resistance
  float reading = analogRead(THERMISTORPIN);
  
  Serial.print("Analog reading: ");
  Serial.println(reading);

  reading = (1023 / reading) - 1;
  reading = SERIESRESISTOR / reading;
  
  Serial.print("Thermistor resistance: ");
  Serial.println(reading);

  delay(1000);

  // getting temperature using library
  temp = thermistor.read();
  Serial.print("Temp in 1/10 ºC : ");
  Serial.println(temp);

  delay(5000);
}
