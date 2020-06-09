#define total_rpm A0 //5k potentiometer
#define gear_up 2    //push button 1 for gear up
#define gear_down 3  //push button 2 for gear down
#define _7_seg_1 23
#define _7_seg_2 22
#define _7_seg_3 24
//=========[pins for speed display]==[2 - 7segments multiplexed]===
#define pinA_1 30
#define pinB_1 32
#define pinC_1 42
#define pinD_1 40
#define pinE_1 38
#define pinF_1 34
#define pinG_1 36
#define pinDp_1 44
//====================[pins for gears display]====================
#define pinA_2 50
#define pinB_2 52
#define pinC_2 51
#define pinD_2 49 
#define pinE_2 47
#define pinF_2 48
#define pinG_2 46
#define pinDp_2 24
int gear =0;

void setup() {
  pinMode(total_rpm,INPUT);
  pinMode(gear_up, INPUT);
  pinMode(gear_down,INPUT);
  pinMode(_7_seg_1 , OUTPUT);
  pinMode(_7_seg_2 , OUTPUT);
  pinMode(_7_seg_3 , OUTPUT);
  //================[pins for speed display]===============
  pinMode(pinA_1,OUTPUT);
  pinMode(pinB_1,OUTPUT);
  pinMode(pinC_1,OUTPUT);
  pinMode(pinD_1,OUTPUT);
  pinMode(pinE_1,OUTPUT);
  pinMode(pinF_1,OUTPUT);
  pinMode(pinG_1,OUTPUT);
  pinMode(pinDp_1,OUTPUT);

  //================[pins for gears display]===============
  pinMode(pinA_2,OUTPUT);
  pinMode(pinB_2,OUTPUT);
  pinMode(pinC_2,OUTPUT);
  pinMode(pinD_2,OUTPUT);
  pinMode(pinE_2,OUTPUT);
  pinMode(pinF_2,OUTPUT);
  pinMode(pinG_2,OUTPUT);
  pinMode(pinDp_2,OUTPUT);

}

int Rpms(){
   int data = analogRead(total_rpm);
    return data*10;
  }
//========================[incrementing gears with respect to push button]==========

int Gears(){
  delay(100);
  if(digitalRead(gear_up) == HIGH){
      gear=gear+1;
      if(gear>=3){
        gear =3;
        }
      }
    if(digitalRead(gear_down)==HIGH){
      gear=gear-1;
      if(gear<=0){
        gear=0;
        }
      }
     return gear;
}
//=======================[Calculate speed per incremental gear supplied]==========
int Speed(){
  int speedd=0;
  if(Gears()==1){
    speedd = Rpms()/341;
    }
  if(Gears()==2){
    speedd = Rpms()/170.5;
    }
  if(Gears()==3){
    speedd = Rpms()/99.320;
    }
  return speedd;
  }
  
  //=======================[Common switching for displaying values]===================
void common_switch(int selector){
    digitalWrite(_7_seg_1,HIGH);//enable 7 segment common ground to display
    digitalWrite(_7_seg_2,HIGH);//enable 7 segment common ground to display
    int Selector = selector;
    switch(selector){
      case 1:
        digitalWrite(_7_seg_1,LOW);
        break;
      case 2:
        digitalWrite(_7_seg_2,LOW);
        break;
      }
  }

//================[7 Segment digits [0-10/A]]=======================
void Speed_Digits(int value){
  int speedd= value;
  switch(speedd){
        case 0:
        digitalWrite(pinA_1,HIGH);
        digitalWrite(pinB_1,HIGH);
        digitalWrite(pinC_1,HIGH);
        digitalWrite(pinD_1,HIGH);
        digitalWrite(pinE_1,HIGH);
        digitalWrite(pinF_1,HIGH);
        digitalWrite(pinG_1,LOW);
      break;
        case 1:
        digitalWrite(pinA_1,LOW);
        digitalWrite(pinB_1,HIGH);
        digitalWrite(pinC_1,HIGH);
        digitalWrite(pinD_1,LOW);
        digitalWrite(pinE_1,LOW);
        digitalWrite(pinF_1,LOW);
        digitalWrite(pinG_1,LOW);
      break;
        case 2:
        digitalWrite(pinA_1,HIGH);
        digitalWrite(pinB_1,HIGH);
        digitalWrite(pinC_1,LOW);
        digitalWrite(pinD_1,HIGH);
        digitalWrite(pinE_1,HIGH);
        digitalWrite(pinF_1,LOW);
        digitalWrite(pinG_1,HIGH);
      break;
        case 3:
        digitalWrite(pinA_1,HIGH);
        digitalWrite(pinB_1,HIGH);
        digitalWrite(pinC_1,HIGH);
        digitalWrite(pinD_1,HIGH);
        digitalWrite(pinE_1,LOW);
        digitalWrite(pinF_1,LOW);
        digitalWrite(pinG_1,HIGH);
      break;
        case 4:
        digitalWrite(pinA_1,LOW);
        digitalWrite(pinB_1,HIGH);
        digitalWrite(pinC_1,HIGH);
        digitalWrite(pinD_1,LOW);
        digitalWrite(pinE_1,LOW);
        digitalWrite(pinF_1,HIGH);
        digitalWrite(pinG_1,HIGH);
      break;
    case 5:
        digitalWrite(pinA_1,HIGH);
        digitalWrite(pinB_1,LOW);
        digitalWrite(pinC_1,HIGH);
        digitalWrite(pinD_1,HIGH);
        digitalWrite(pinE_1,LOW);
        digitalWrite(pinF_1,HIGH);
        digitalWrite(pinG_1,HIGH);
      break;
        case 6:
        digitalWrite(pinA_1,HIGH);
        digitalWrite(pinB_1,LOW);
        digitalWrite(pinC_1,HIGH);
        digitalWrite(pinD_1,HIGH);
        digitalWrite(pinE_1,HIGH);
        digitalWrite(pinF_1,HIGH);
        digitalWrite(pinG_1,HIGH);
      break;
        case 7:
        digitalWrite(pinA_1,HIGH);
        digitalWrite(pinB_1,HIGH);
        digitalWrite(pinC_1,HIGH);
        digitalWrite(pinD_1,LOW);
        digitalWrite(pinE_1,LOW);
        digitalWrite(pinF_1,LOW);
        digitalWrite(pinG_1,LOW);
      break;
        case 8:
        digitalWrite(pinA_1,HIGH);
        digitalWrite(pinB_1,HIGH);
        digitalWrite(pinC_1,HIGH);
        digitalWrite(pinD_1,HIGH);
        digitalWrite(pinE_1,HIGH);
        digitalWrite(pinF_1,HIGH);
        digitalWrite(pinG_1,HIGH);
      break;
        case 9:
        digitalWrite(pinA_1,HIGH);
        digitalWrite(pinB_1,HIGH);
        digitalWrite(pinC_1,HIGH);
        digitalWrite(pinD_1,HIGH);
        digitalWrite(pinE_1,LOW);
        digitalWrite(pinF_1,HIGH);
        digitalWrite(pinG_1,HIGH);
      break;
        case 10:
        digitalWrite(pinA_1,HIGH);
        digitalWrite(pinB_1,HIGH);
        digitalWrite(pinC_1,HIGH);
        digitalWrite(pinD_1,LOW);
        digitalWrite(pinE_1,HIGH);
        digitalWrite(pinF_1,HIGH);
        digitalWrite(pinG_1,HIGH);
      break;
  
   }
}
//=================[7 segment digits from [0-3]=====================
void Gear_Digits(){
  digitalWrite(_7_seg_3,LOW);//enable 7 segment common ground to display
  int gear = Gears();
  switch(gear){
        case 0:
        digitalWrite(pinA_2,HIGH);
        digitalWrite(pinB_2,HIGH);
        digitalWrite(pinC_2,HIGH);
        digitalWrite(pinD_2,HIGH);
        digitalWrite(pinE_2,HIGH);
        digitalWrite(pinF_2,HIGH);
        digitalWrite(pinG_2,LOW);
      break;
        case 1:
        digitalWrite(pinA_2,LOW);
        digitalWrite(pinB_2,HIGH);
        digitalWrite(pinC_2,HIGH);
        digitalWrite(pinD_2,LOW);
        digitalWrite(pinE_2,LOW);
        digitalWrite(pinF_2,LOW);
        digitalWrite(pinG_2,LOW);
      break;
        case 2:
        digitalWrite(pinA_2,HIGH);
        digitalWrite(pinB_2,HIGH);
        digitalWrite(pinC_2,LOW);
        digitalWrite(pinD_2,HIGH);
        digitalWrite(pinE_2,HIGH);
        digitalWrite(pinF_2,LOW);
        digitalWrite(pinG_2,HIGH);
      break;
        case 3:
        digitalWrite(pinA_2,HIGH);
        digitalWrite(pinB_2,HIGH);
        digitalWrite(pinC_2,HIGH);
        digitalWrite(pinD_2,HIGH);
        digitalWrite(pinE_2,LOW);
        digitalWrite(pinF_2,LOW);
        digitalWrite(pinG_2,HIGH);
      break;
      default:
        break;
  }
}

void Display_speed_and_Gears(){
  String number=String(Speed());
    if(Speed()<10){
       Speed_Digits(0);
       common_switch(1);
       delay(5);
       Speed_Digits(Speed());
       common_switch(2);
       delay(5);
      }
    if(Speed()>=10 && Speed()<100){
       Speed_Digits(number[0]);
       common_switch(1);
       delay(5);
       Speed_Digits(number[1]);
       common_switch(2);
       delay(5);   
      }
    Gear_Digits();
  }

void loop() {
  Serial.begin(9600);
  Display_speed_and_Gears();
   Serial.println(Speed());
   delay(5);
}
