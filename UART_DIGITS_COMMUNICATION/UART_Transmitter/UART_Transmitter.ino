//#include <SoftwareSerial.h>
#include "_7_Seg_lib.h"
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Init();
}

void loop() {
      int received_Data;
      int number ;
        if(Serial1.available()>=0x00){
          received_Data = int(Serial1.read());
          }
          delay(1000);
        if(Serial1.availableForWrite()>=0x00){
          number = random(0x00,0x0A);
          Serial1.write(number);
       }
       Display(received_Data);
       Serial.println(number);
}
