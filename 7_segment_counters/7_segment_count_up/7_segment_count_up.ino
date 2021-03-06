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

#define DIGIT_1 0x02 
#define DIGIT_2 0x03
#define DIGIT_3 0x04
#define DIGIT_4 0x05

/*========================== Arduino simplified functionality ===============*/
#define ENABLE HIGH 
#define DISABLE LOW 
#define TIMER 0x3E8
#define TRASNFER_SPEED 0x02580


void setup() {
  Serial.begin(TRASNFER_SPEED);
}

void Counter(){
  Segment segment(A,B,C,D,E,F,G,Dp,'C');
    int counter =0x00;
    while(true){
        if(counter ==10){
          counter = 0x00;
          delay(500);
          }
          segment.Display(counter);
          counter = counter + 0x01;
          delay(TIMER);
      }
  }
void loop() {
 Counter();
 
}
