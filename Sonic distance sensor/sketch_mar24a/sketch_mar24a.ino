#include <LiquidCrystal.h>

#define vcc 40
#define gnd 41
#define echo 23
#define trig 22 
#define Interface 31,29,34,32,30,28
#define Red_LED 3
#define Green_LED 2
LiquidCrystal LCD(Interface);

void setup() {
  Serial.begin(9600);
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(vcc , OUTPUT);
  pinMode(gnd , OUTPUT);
  pinMode(Red_LED , OUTPUT);
  pinMode(Green_LED , OUTPUT);
  LCD.begin(16,2);
  LCD.print("Distance :");
}

void SonicDistance(){
  Serial.begin(9600);
  digitalWrite(trig , LOW);
  digitalWrite(vcc , HIGH);
  digitalWrite(gnd , LOW);
  long duration , Distance;
  while(true){
      digitalWrite(trig , HIGH);
      digitalWrite(trig , LOW);
      duration = pulseIn(echo , HIGH);
      Distance =  duration /58;
      LCD.setCursor(0 , 1);
      LCD.print(String(Distance)+" cm");
      Serial.println("Distance :"+String(Distance));
      if(Distance <=5){
        digitalWrite(Red_LED , HIGH);
        delay(50);
        digitalWrite(Red_LED , LOW);
        delay(50);
        }else if(Distance>5){
          digitalWrite(Green_LED , HIGH);
          delay(100);
          digitalWrite(Green_LED , LOW);
          delay(100);
        }
    }
}


   void loop() {
    SonicDistance();
}
