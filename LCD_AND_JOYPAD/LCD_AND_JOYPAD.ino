#include <LiquidCrystal.h>
#define READ_X_VALUES A0
#define READ_Y_VALUES A1
    
 //(RS,EN,D4,D5,D6.D7)
#define Interface 32,30,28,26,24,22

LiquidCrystal LCD(Interface);

void setup() {
  Serial.begin(9600);
  pinMode(READ_X_VALUES, INPUT);
  pinMode(READ_Y_VALUES,INPUT);
  LCD.begin(16,2);    
  LCD.clear(); 
  LCD.display();
}
//==============================[Reading x values of joypad]========================
int Read_X(){
  return analogRead(READ_X_VALUES);

  }
  //=============================[reading y values of joypad]=====================
int Read_Y(){
  return analogRead(READ_Y_VALUES);
  }
  
//================================[Dissplaying data from joypad to lcd]================  
void Display_Data(){
  String Initials = "Initials: K Mphuthi";
  String Student_Nuumber = "Stdnt No: 220054371 ";
  LCD.setCursor(0 , 0);
  LCD.print(Initials);
  LCD.setCursor(0 , 1);
  LCD.print(Student_Nuumber);
  if(Read_X() <0x3E8 || Read_Y() < 0x03EB){
      LCD.setCursor(0x20,0x00);
      LCD.print(" ");
      LCD.setCursor(0x14,0x00);  
      LCD.print("X Value :"+String((Read_X())));
      LCD.setCursor(0x20,0x01);
      LCD.print(" ");
      LCD.setCursor(0x14,0x01);
      LCD.print("Y Value :"+String((Read_Y())));
    }else{
  LCD.setCursor(0x14,0x00);  
  LCD.print("X Value :"+String((Read_X())));
  LCD.setCursor(0x14,0x01);
  LCD.print("Y Value :"+String((Read_Y())));
      }
  
}
//=======[loop main function calling the display data dunction]==============
void loop() {
  Display_Data();
}
