//#include "Display.h"
//#################################
//#   R.M Nabo  214111636         #
//#################################
#include <LiquidCrystal.h>
 
#define BATTERY_TYPE_ONE 0x06
#define BATTERY_TYPE_TWO 0x07
#define BUTTON_ONE_LED 0x0A
#define BUTTON_TWO_LED 0x0B
#define INTERFACE 32,30,28,26,24,22
#define ADC_PIN A0 
#define PWR_PIN A1
#define CHARGER_LOW_PIN 0x08
#define CHARGER_OFF_PIN 0x09
#define CHARGE_READING A2
#define BATTERY_READING A3
#define AMP_READING A4
int ADC_VAL = 0x00;  
int PWR_VAL = 0x00;
int Voltage = 0x00;
//==================================================[Button one variables declaratuin and initializtion]=========================================
int button_one_state = 0x00;
int last_button_one_state = 0x00;
volatile bool button_one = false;
//==================================================[Button two variables declarations and initialiation]=========================================
int button_two_state = 0x00;
int last_button_two_state = 0x00;
volatile bool button_two = false;
int last_button_state = 0x00;
int selected_battery = 0x00;
//==================================================[LCD passing parameters PINs connected]=========================================
LiquidCrystal LCD(INTERFACE);



void setup() {
  Serial.begin(9600);
   LCD.begin(16,0x02);
  pinMode(CHARGER_OFF_PIN,OUTPUT);
  pinMode(CHARGER_LOW_PIN,OUTPUT); 
  pinMode(BATTERY_TYPE_ONE,INPUT_PULLUP);
  pinMode(BATTERY_TYPE_TWO,INPUT_PULLUP);
  pinMode(BUTTON_ONE_LED,OUTPUT);
  pinMode(BUTTON_TWO_LED,OUTPUT);
  digitalWrite(BUTTON_ONE_LED,LOW);
  digitalWrite(BUTTON_TWO_LED,LOW);
  attachInterrupt(digitalPinToInterrupt(BATTERY_TYPE_ONE),check_battery_one_button,RISING);
  attachInterrupt(digitalPinToInterrupt(BATTERY_TYPE_TWO),check_battery_two_button,RISING);
  LCD.setCursor(0x00, 0x00);
  LCD.print ("Arduino controld" );
  LCD.setCursor(0x00, 0x01);
  LCD.print("15V bttry chrgr");
  delay(1000);
  LCD.clear();
  Display_Info("Select battery type");
}




//==================================================[Battery one button check function]=========================================
void check_battery_one_button(){
        button_one != button_one;
 }


//==================================================[Battery two button check function]=========================================


void check_battery_two_button(){
        button_two != button_two;
}

//==================================================[Selecting type of battery check]=========================================
void Select_battery_type(){
      check_battery_one_button();
      check_battery_two_button();
      Serial.println("[===============button one state==================]");
      Serial.println(digitalRead(BATTERY_TYPE_ONE));
      
      Serial.println("[===============button two state==================]");
      Serial.println(digitalRead(BATTERY_TYPE_TWO));
     if(button_one ==true){
          button_one  = false;
          Display_Info("15V Lead-Acid Bttry");
          digitalWrite(BUTTON_ONE_LED,HIGH);
          digitalWrite(BUTTON_TWO_LED,LOW);   
      }
      if(button_two == true){
          button_two = false;
          Display_Info("15V AGM Battery");
          digitalWrite(BUTTON_ONE_LED,LOW);
          digitalWrite(BUTTON_TWO_LED,HIGH);
      }
     
}

//==================================================[charging battery functionallity]=========================================

void Battery_charge(){
  Select_battery_type();
  if(button_one == true || button_two == true){
                PWR_VAL = analogRead(PWR_PIN);
                ADC_VAL = analogRead(ADC_PIN);
                Voltage = (ADC_VAL+0x02)/0x04;
                Display_Info("");
                
                
                if(Voltage > 130){
                    digitalWrite(CHARGER_OFF_PIN, LOW);
                    digitalWrite(CHARGER_LOW_PIN, HIGH);
                    Display_Info("Battery Full");
                    if(PWR_VAL <600){
                        Display_Info("Charger is off");
                      }
                  }


                
                
                else if(Voltage <=15){
                  Display_Info("No Battery ");
                  if(PWR_VAL < 600){
                       Display_Info("Charger is off");
                    }
                    else{
                        Display_Info("Not Charging ");
                      }
                  }
                
                
                
                else if(Voltage <80){
                    Display_Info("Battery Dead");
                    if(PWR_VAL<600){
                        Display_Info("Charger is off");
                      }
                    else{
                        Display_Info("Slow charging");
                        }
                    delay(1000);
                    digitalWrite(CHARGER_OFF_PIN,LOW);
                    digitalWrite(CHARGER_LOW_PIN,HIGH);
                    }
                else if ( Voltage<110 )
                {
                  digitalWrite(CHARGER_OFF_PIN, LOW);   
                  digitalWrite(CHARGER_LOW_PIN, LOW);
                  Display_Info("BATT:WEAK" ); 
                  if(PWR_VAL<600){
                      Display_Info( " CHARGER IS OFF " );
                    }else {
                      Display_Info(" FAST CHARGING. " );
                      } 
                }  
          }
  
  }



//==================================================[Display information function]=========================================
  
void Display_Info(String Info){
    int Info_length = Info.length();
    if(Info_length<=16){
        LCD.clear();
        LCD.setCursor(0x00 , 0x00);
        LCD.print(Info);
      }
     else{
          LCD.clear();
          LCD.setCursor(0x00,0x00);
          LCD.print(Info);        
            
       }
 }
     

//==================================================[Main loop function]=========================================

void loop() {
  Select_battery_type();
}
