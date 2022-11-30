#include <Wire.h>
#include <LiquidCrystal_I2C.h>//Import I2C library

#define Analog A2
#define Button A3

int state = 0;

LiquidCrystal_I2C lcd(0x20, 16, 2); // run ic2_scanner sketch and get the IC2 address, which is 0x3f in my case,it could be 0x3f in many cases


void setup()
{
  Serial.begin(9600);
  lcd.init();// initialize the lcd
}

void loop()
{
  state = digitalRead(Button);
  float value = analogRead(Analog);
  Serial.print("\n State = "+String(state));
  if(state == HIGH){
      digitalWrite(8, HIGH);
      delay(2000);
      digitalWrite(8, LOW);
    }
  // set cursor to first line
  lcd.setCursor(5, 0);

  // Print a message to the LCD.
  lcd.backlight();
  lcd.print("Hello!");
  lcd.setCursor(2, 1);
  lcd.print("MICRODIGISOFT");
}
