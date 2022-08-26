#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("DHT test");
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.clear();
  if (isnan(t) || isnan(h)) {
    lcd.setCursor(0, 0);
    lcd.print("Can't get reading");
    lcd.setCursor(0, 1);
    lcd.print("from DHT");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Hum: ");
    lcd.print(h);
    lcd.print(" %");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print(" *C");
  }
  delay(5000);
}
