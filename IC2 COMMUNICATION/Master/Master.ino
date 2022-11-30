#include <Wire.h>
#include "Seg_Lib.h"
#define Slave1_addr 0x01
#define CODE 99
void setup(){
    Serial.begin(9600);
    Wire.begin();
    Init(52, 50 ,48,  46, 44, 42, 40);
}
//============================================
void Connect(int addr){
    Wire.beginTransmission(addr);
  }
//============================================  
void Transmit(int Data){
    Wire.write(Data);
  }
//============================================
void Disconnect(){
    Wire.endTransmission();
  }
//=============================================
void Request(int addr,int verify){
    Wire.requestFrom(addr,verify);
  }
void loop(){
  int number =random(0,0x0A);
  String respond;
  Serial.println(number);
  Display(number);
  Connect(Slave1_addr);
  Transmit(number);
  Disconnect();
  Request(Slave1_addr,CODE);
  while(Wire.available()){
    char D_byte = Wire.read();
    respond += D_byte;
    }
    Serial.println("Responds from slave "+respond);
  delay(1000);



  
}
