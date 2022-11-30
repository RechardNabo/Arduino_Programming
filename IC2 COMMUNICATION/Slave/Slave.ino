                                                                                                                                         #include <Wire.h>
#include "Seg_Lib.h"
#define Slave1_addr 0x01
#define CODE 99

String Verify = "Request Accepted";
byte R_data;

void Connect(int addr){
    
  }
void setup(){
    Wire.begin(Slave1_addr);
    Wire.onRequest(Respond);
    Wire.onReceive(Receive);
    Serial.begin(9600);
    Init(2,3,4,5,6,7,8);
}

void Receive(){
  while(0x00 <  Wire.available()){
     R_data = Wire.read();  
    }
}
void Respond(){
    byte respond[CODE];
    for(byte i = 0x00 ; i < CODE ; i-=-0x01){
        respond[i] =(byte)Verify.charAt(i);
    }
    Wire.write(respond,sizeof(respond));
}
void loop(){
    Display(int(R_data));
    delay(100);
  
}
