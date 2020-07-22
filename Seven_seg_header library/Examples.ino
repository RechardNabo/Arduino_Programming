/*
      steps 1->#include "Seeven_seg_lib_nonmultiplex.h"
      step 2 -> created an object of the class in header file
             ->constructor taking below parameters(A-decimal point are integers and segType is a charater (a = anode , c = cathode))
             ->Segment( A, B, C, D, E, F, G, decimal point, segType)
             ->Segment(int , int , int , int , int , int ,int , int , char)
             ->         A
                    =========                           
                    =       =
                  F =       =  B
                    =   G   =
                    =========
                    =       =
                  E =       =  C
                    =       =
                    ========= # decimal point 
                        D
      step 3 -> Use the object to access the display funtion
             -> Segment.Display( int number);          
    
*/
// Examples bellow

#include "Seeven_seg_lib_nonmultiplex.h"
#define ground1 2
#define ground2 3
void setup() {
  pinMode(ground1,OUTPUT);
  pinMode(ground2,OUTPUT);
}

//==============================================[up counter function]=============================================
void Upcounter(){
  Segment Segment(35,37,43,41,39,33,31,45,'A');
  digitalWrite(ground1,LOW);
  digitalWrite(ground2,LOW);
  int counter = 0x00;
  while(true){
    if(counter ==0x0A){
       counter=0x00;
      }
    Segment.Display(counter);
    delay(1000);
    counter = counter+0x01;
    }
  }

//==============================================[down counter function]=============================================
void Downcounter(){
  Segment Segment(35,37,43,41,39,33,31,45,'A');
  digitalWrite(ground1,LOW);
  digitalWrite(ground2,LOW);
  int counter = 0x09;
  while(true){
    if(counter ==0x00){
       counter=0x09;;
      }
    Segment.Display(counter);
    delay(1000);
    counter = counter-0x01;
    }
  }  
//==============================================[display number function]=============================================
void myNumber(){
    Segment Segment(35,37,43,41,39,33,31,45,'A');
    digitalWrite(ground1,LOW);
    digitalWrite(ground2,LOW);
    Segment.Display(0x08); // display 8 in hex 0x08  
  }

void loop() {
  Upcounter();
  //Downcounter();
  //myNumber();
}
