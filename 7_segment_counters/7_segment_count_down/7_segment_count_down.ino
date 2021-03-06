#include "Seven_seg_lib_nonmultiplex.h"


//============================= 4 digit 7 segment=============================== 
#define A 22
#define B 24
#define C 26
#define D 28
#define E 30
#define F 32
#define G 34
#define Dp  36


//========================== Arduino simplified functionality ===============*/
#define TIMER 0x3E8
#define TRASNFER_SPEED 0x02580

//==============================[Program setup]================================
void setup() {
  Serial.begin(TRASNFER_SPEED);
}

void Counter(){
  Segment segment(A,B,C,D,E,F,G,Dp,'C');
    int counter =0x09;
    while(true){
        if(counter ==-0x01){
          counter = 0x09;
          delay(500);
          }
          segment.Display(counter);
          counter = counter - 0x01;
          delay(TIMER);
      }
  }
void loop() {
 Counter();
 
}
