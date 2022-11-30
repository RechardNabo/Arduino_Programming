#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
/*PIN_SCE   4
PIN_RESET 3
PIN_DC    5
PIN_SDIN  11
PIN_SCLK  13*/
//======================== Adafruit_PCD8544(CLK, DIN ,D/C  ,CE   ,RST  );
Adafruit_PCD8544 display = Adafruit_PCD8544(0x02, 0x03, 0x04, 0x05, 0x06); 

const int X_pin = A0; // analog pin connected to X output
//const int Y_pin = A1; // analog pin connected to Y output
int score=0;
int val1;
void setup()   
{
  Serial.begin(9600);
  display.begin();
  display.setContrast(60);
  display.clearDisplay(); 
  display.setTextSize(0x01);
  display.clearDisplay();
  display.setTextColor(BLACK, WHITE);
  display.setCursor(13, 0);
  display.print(" Starting");
  display.drawFastHLine(0,10,83,BLACK);
  display.setCursor(0,15);  
  display.setTextSize(2);      
  display.setTextColor(BLACK);
  display.setCursor(10,12);
  display.print("Catch\n  Ball");
  display.setCursor(10,50);
  display.print("utopian");
  display.display();
  delay(4000);
}
void loop() 
{
  int randX = random(2,83);
  int Y=15;
  while(Y<=46)
  {
  display.clearDisplay();
  bucket();
    display.setTextSize(0x01);
  display.setCursor(10,2);
  display.println("Points : ");
  display.setCursor(60,2);
  display.println(score);
  display.fillCircle(randX, Y, 3, BLACK);
  display.drawRect(1, 1, 83, 47, BLACK);
  display.drawLine(1, 10, 83, 10, BLACK);
  display.display();
  delay(80);
  Y=Y+1;
  if(val1>=randX-2 && val1<=randX+2 && Y>=40)
  {
    Y=48;
    score=score+1;
    display.setCursor(60,2);
    display.println(score);
  }
  else if(Y==47)
  {
      display.setContrast(30);
      display.clearDisplay();
      display.setTextColor(BLACK, WHITE);
      display.setCursor(13, 0);
      display.print("Catch Ball");
      display.drawFastHLine(0,10,83,BLACK);
      display.setTextColor(BLACK);       
      display.setTextSize(1);
      display.setCursor(15,20);
      display.print("Game Over");
      display.setCursor(15,35);
      display.print("Score: ");
      display.print(score);
      display.setCursor(15,40);
      display.display(); 
      delay(4000);
    score=0;

  }
  }
}
void bucket()
{
  display.clearDisplay();
  val1 = analogRead(X_pin);
  val1 = map(val1, 0, 1014, 0, 83);
  //val2 = analogRead(Y_pin);
  //val2 = map(val2, 0, 1014, 0, 47);
  display.drawLine(val1-5, 40, val1+5, 40, BLACK);
  display.drawLine(val1-5, 39, val1+5, 39, BLACK);
  display.drawLine(val1-5, 40, val1-3, 46, BLACK);
  display.drawLine(val1+5, 40, val1+2, 46, BLACK);
  display.display();
  //Serial.println(val1);
  //Serial.print(val2);
}
