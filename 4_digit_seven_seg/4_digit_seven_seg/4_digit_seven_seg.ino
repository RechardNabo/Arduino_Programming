#define D1 35
#define D2 37
#define D3 39
#define D4 41
#define pinA 31
#define pinB 29
#define pinC 49
#define pinD 45
#define pinE 43
#define pinF 33
#define pinG 51
#define pin_Dp 47

void setup() {
  pinMode(D1 , OUTPUT);
  pinMode(D2 , OUTPUT);
  pinMode(D3 , OUTPUT);
  pinMode(D4 , OUTPUT);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pin_Dp, OUTPUT);
}

void digit_switch(int digit){
  int switcher= digit;
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  switch(switcher){
      case 1 :
        digitalWrite(D1 , HIGH);
        break;
      case 2 :
        digitalWrite(D2, HIGH);
        break;
      case 3 :
        digitalWrite(D3 , HIGH);
        break;
      case 4 :
        digitalWrite(D4 , HIGH);
        break;
    }
  }
void value(int Value){
    int value=Value;
    switch(value){
        case 0 :
        digitalWrite(pinA , LOW);
        digitalWrite(pinB , LOW);
        digitalWrite(pinC , LOW);
        digitalWrite(pinD , LOW);
        digitalWrite(pinE , LOW);
        digitalWrite(pinF , LOW);
        digitalWrite(pinG , HIGH);
        digitalWrite(pin_Dp , HIGH);
        break;

      case 1:
        digitalWrite(pinA , HIGH);
        digitalWrite(pinB , LOW);
        digitalWrite(pinC , LOW);
        digitalWrite(pinD , HIGH);
        digitalWrite(pinE , HIGH);
        digitalWrite(pinF , HIGH);
        digitalWrite(pinG , HIGH);
        digitalWrite(pin_Dp ,HIGH);
        break;
      case 2:
        digitalWrite(pinA , LOW);
        digitalWrite(pinB , LOW);
        digitalWrite(pinC , HIGH);
        digitalWrite(pinD , LOW);
        digitalWrite(pinE , LOW);
        digitalWrite(pinF , HIGH);
        digitalWrite(pinG , LOW);
        digitalWrite(pin_Dp , HIGH);
        break;
      case 3:
        digitalWrite(pinA , LOW);
        digitalWrite(pinB , LOW);
        digitalWrite(pinC , LOW);
        digitalWrite(pinD , LOW);
        digitalWrite(pinE , HIGH);
        digitalWrite(pinF , HIGH);
        digitalWrite(pinG , LOW);
        digitalWrite(pin_Dp , HIGH);
        break;
      
      case 4:
        digitalWrite(pinA , HIGH);
        digitalWrite(pinB , LOW);
        digitalWrite(pinC , LOW);
        digitalWrite(pinD , HIGH);
        digitalWrite(pinE , HIGH);
        digitalWrite(pinF , LOW);
        digitalWrite(pinG , LOW);
        digitalWrite(pin_Dp , HIGH);
        break;
      case 5:
        
        digitalWrite(pinA , LOW);
        digitalWrite(pinB , HIGH);
        digitalWrite(pinC , LOW);
        digitalWrite(pinD , LOW);
        digitalWrite(pinE , HIGH);
        digitalWrite(pinF , LOW);
        digitalWrite(pinG , LOW);
        digitalWrite(pin_Dp , HIGH);
        break;
        
      case 6:
        
        digitalWrite(pinA , LOW);
        digitalWrite(pinB , HIGH);
        digitalWrite(pinC , LOW);
        digitalWrite(pinD , LOW);
        digitalWrite(pinE , LOW);
        digitalWrite(pinF , LOW);
        digitalWrite(pinG , LOW);
        digitalWrite(pin_Dp , HIGH);
        break;
      
      case 7:
        
        digitalWrite(pinA , LOW);
        digitalWrite(pinB , LOW);
        digitalWrite(pinC , LOW);
        digitalWrite(pinD , HIGH);
        digitalWrite(pinE , HIGH);
        digitalWrite(pinF , HIGH);
        digitalWrite(pinG , HIGH);
        digitalWrite(pin_Dp , HIGH);
        break;
      case 8:
        
        digitalWrite(pinA , LOW);
        digitalWrite(pinB , LOW);
        digitalWrite(pinC , LOW);
        digitalWrite(pinD , LOW);
        digitalWrite(pinE , LOW);
        digitalWrite(pinF , LOW);
        digitalWrite(pinG , LOW);
        digitalWrite(pin_Dp , HIGH);
        break;
       
       case 9:
        digitalWrite(pinA , LOW);
        digitalWrite(pinB , LOW);
        digitalWrite(pinC , LOW);
        digitalWrite(pinD , LOW);
        digitalWrite(pinE , HIGH);
        digitalWrite(pinF , LOW);
        digitalWrite(pinG , LOW);
        digitalWrite(pin_Dp , HIGH);
        break;
   }
  }

void loop() {
int counter = 0;
while(counter <10){
digit_switch(1);
value(0);
delay(5);
digit_switch(2);
value(0);
delay(5);
digit_switch(3);
value(0);
delay(5);
digit_switch(4);
value(counter);
delay(5);
counter++;
  }

 }
     
  
     
