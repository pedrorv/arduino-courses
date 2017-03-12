#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Luminosity:");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(analogRead(A0));
  if (analogRead(A0) < 1000) {
    lcd.setCursor(3, 1);
    lcd.print(" ");
  }
  delay(50);
}
