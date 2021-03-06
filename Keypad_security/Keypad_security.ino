#include <Keypad.h>
#define ACCESS_GRANTED 0x02
#define ACCESS_DENIED 0x03
#define ON HIGH
#define OFF LOW
#define SEND_DATA OUTPUT
#define ROWS  0x04
#define COLUMNS 0x04


char keys[ROWS][COLUMNS] = {{'1','2','3','A'},
                            {'4','5','6','B'},
                            {'7','8','9','C'},
                            {'*','0','#','D'}};
byte ROW_PINS[ROWS] = {22,24,26,28} ;
byte COLUMN_PINS[COLUMNS] = {30,32,34,36};

String Security_check = "";
String Security_pin = "9956B";

Keypad keypad = Keypad(makeKeymap(keys),COLUMN_PINS,ROW_PINS,ROWS,COLUMNS);

void setup() {
  Serial.begin(9600);
  pinMode(ACCESS_GRANTED , SEND_DATA);
  pinMode(ACCESS_DENIED , SEND_DATA);
}

void TEST_KEYS(){
  char key = keypad.getKey();
  if(key){
    Security_check = Security_check+key;
    if(key=='*'){
        Security_check = "";
        digitalWrite(ACCESS_GRANTED,OFF);
      }
    }
  if(Security_check.length()==0x05 && Security_pin == Security_check){
        digitalWrite(ACCESS_GRANTED,ON);
      }
    if(Security_check.length()==0x05 && Security_pin != Security_check){
          digitalWrite(ACCESS_DENIED,ON);
          delay(2000);
          digitalWrite(ACCESS_DENIED,OFF);
          Security_check = "";
      }
  }

void loop() {
  TEST_KEYS();
}
