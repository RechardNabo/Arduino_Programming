
#define Pina 2
#define pinb 3
#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
#define H 9
typedef int number;
number  entered_number;
number counter = 0;
 // inputs
void setup() {
Serial.begin(9600);
pinMode(A , OUTPUT);
pinMode(B , OUTPUT);
pinMode(C , OUTPUT);
pinMode(D , OUTPUT);
pinMode(E , OUTPUT);
pinMode(F , OUTPUT);
pinMode(G , OUTPUT);
pinMode(H , OUTPUT);
}


void operating(){
  int pin_led = 13;
  pinMode(pin_led , OUTPUT);
  digitalWrite(pin_led , HIGH);
  delay(500);
  digitalWrite(pin_led , LOW);
  delay(500);
  }

void Displayer(int entered_number){
  if(entered_number == 0){    
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, HIGH);

    }
   else if(entered_number ==1){
    
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(H, HIGH);
    }
   else if(entered_number ==2){
    
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(H, HIGH);
    }
   else if(entered_number ==3){
    
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, HIGH);
    }
   else if(entered_number ==4){
    
  digitalWrite(A, HIGH);//;
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);//
  digitalWrite(D, HIGH);//
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(H, HIGH);

    }
   else if(entered_number ==5){
    
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, HIGH);
    }
   else if(entered_number ==6){
    
  
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, HIGH);
}
   else if(entered_number ==7){
    
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(H, HIGH);
   }
   else if (entered_number == 8){
    
  digitalWrite(A, HIGH);//;
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);//
  digitalWrite(D, HIGH);//
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, HIGH);

    }else if(entered_number == 9){
      
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, HIGH);
      }
 
  }
void loop() {
operating();
delay(300);
for(int counter = 0 ; counter < 10 ; counter++){
    delay(1000);
    Displayer(counter);
  }
}
