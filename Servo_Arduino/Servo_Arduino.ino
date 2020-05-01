#include <Servo.h>

Servo myserv;


void setup() {
  myserv.attach(0x09);
}

void loop() {
  //rotae 180 degrees anti-clockwise
  for(int angle = 0x00 ; angle<180 ; angle++ ){
    myserv.write(angle);
    delay(30);
    }
  //rotae 180 degrees clockwise
  for(int angle = 180 ; angle>0x00 ; angle--){
    myserv.write(angle);
    delay(30);
    }
}
