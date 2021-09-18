/* 
 *  https://www.datasheet-pdf.info/entry/VS1838B
 *  CH-    0xFFA25D
   CH     0xFF629D
   CH+    0xFFE21D
   <<     0xFF22DD
   >>     0xFF02FD
   >||    0xFFC23D
   –      0xFFE01F
   +      0xFFA857
   EQ     0xFF906F
   100+   0xFF9867
   200+   0xFFB04F
   0      0XFF6897
   1      0xFF30CF
   2      0xFF18E7
   3      0xFF7A85
   4      0xFF10EF
   5      0xFF38C7
   6      0xFF5AA5
   7      0xFF42BD
   8      0xFF4AB5
   9      0xFF52AD*/
#include <IRremote.h>

#define LED1 0x04
#define LED2 0x05
#define LED3 0x06
#define LED4 0x07
const byte IR_Receiver = 2;
decode_results results;
IRrecv IrRecv(IR_Receiver);

void setup() {
  Serial.begin(9600);
  Serial.println("\nIR Remote data testing");
  IrRecv.enableIRIn();
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);

}

void loop() {
  //decode_results results;
  int skip = 4294967295;
  if(IrRecv.decode(&results)){
    int data = results.value;
    if(data != skip){
      Serial.println(results.value,HEX);
      if(data == int(0xFF30CF)){
          digitalWrite(LED1,HIGH);
        }
       if(data == int(0xFF18E7)){
          digitalWrite(LED2,HIGH);
        }
       if(data == int(0xFF7A85)){
          digitalWrite(LED3,HIGH);
        }
       if(data == int(0xFF10EF)){
          digitalWrite(LED4,HIGH);
        }
       if(data == int(0XFF6897)){
          digitalWrite(LED1,LOW);
          digitalWrite(LED2,LOW);
          digitalWrite(LED3,LOW);
          digitalWrite(LED4,LOW);
        }
       
      }
      IrRecv.resume();  
    }
}
