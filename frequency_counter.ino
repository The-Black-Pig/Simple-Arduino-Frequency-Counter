// Include Wire Library for I2C
#include <Wire.h>
// Include NewLiquidCrystal Library for I2C
#include <LiquidCrystal_I2C.h>

// Define LCD pinout
const int  en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;

// Define I2C Address - change if reqiuired
const int i2c_addr = 0x25;

LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

const byte interruptPin = 2;

unsigned int i = 0;

void setup() {
  
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Interrupt Powered");
  lcd.setCursor(0,1);
  lcd.print("Freq. Counter");
  delay(2000);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), count, RISING);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Frequency");
}

void loop() {
  
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print(i); lcd.print(" Hz      ");
  i = 0;
}

void count() {
  i++;
}
