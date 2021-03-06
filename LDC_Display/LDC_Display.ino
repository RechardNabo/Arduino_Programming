#include <LiquidCrystal.h>
#define BRIGHTNESS A0 
               //(RS,EN,D4,D5,D6.D7)
#define Interface 32,30,28,26,24,22
double Bightness = 0x00;
LiquidCrystal LCD(Interface);

void setup() {
  Serial.begin(9600);
  pinMode(BRIGHTNESS,INPUT);
  LCD.begin(16,2);
}

void Display(){
  String Initials = "Initials :R.M Nabo";
  String Student_Nuumber = "Student no:2123456";
  Bightness = analogRead(BRIGHTNESS);
  LCD.setCursor(0 , 0);
  LCD.print(Initials);
  LCD.setCursor(0 , 1);
  LCD.print(Student_Nuumber);
  LCD.setCursor(20,1);
  LCD.print("Brightness : "+String(Bightness/10.2));
  Serial.println(Bightness);
}

void loop() {
  Display();
}
