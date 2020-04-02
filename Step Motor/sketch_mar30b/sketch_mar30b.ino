
#define line1 5 
#define line2 4 
#define line3 3 
#define line4 2 
//================[Sonic distance ditector]=========================

void setup(){
  Serial.begin(9200);
  pinMode(line1 , OUTPUT);
  pinMode(line2 , OUTPUT);
  pinMode(line3 , OUTPUT);
  pinMode(line4 , OUTPUT);
  }
//===========================================================================================
void Movement(char direct){
  switch(direct){
    case 'f':
      digitalWrite(line1 , HIGH);
      digitalWrite(line2 , LOW);
      digitalWrite(line3 , LOW);
      digitalWrite(line4 , LOW);
      delay(300);
      
      digitalWrite(line1 , LOW);
      digitalWrite(line2 , HIGH);
      digitalWrite(line3 , LOW);
      digitalWrite(line4 , LOW);
      delay(300);
      
      digitalWrite(line1 , LOW);
      digitalWrite(line2 , LOW);
      digitalWrite(line3 , HIGH);
      digitalWrite(line4 , LOW);
      delay(300);
      
      digitalWrite(line1 , LOW);
      digitalWrite(line2 , LOW);
      digitalWrite(line3 , LOW);
      digitalWrite(line4 , HIGH);
      delay(300);
      break;
      case 'r':
      digitalWrite(line1 , LOW);
      digitalWrite(line2 , LOW);
      digitalWrite(line3 , LOW);
      digitalWrite(line4 , HIGH);
      delay(300);

      digitalWrite(line1 , LOW);
      digitalWrite(line2 , LOW);
      digitalWrite(line3 , HIGH);
      digitalWrite(line4 , LOW);
      delay(300);
      
      digitalWrite(line1 , LOW);
      digitalWrite(line2 , HIGH);
      digitalWrite(line3 , LOW);
      digitalWrite(line4 , LOW);
      delay(300);
      digitalWrite(line1 , HIGH);
      digitalWrite(line2 , LOW);
      digitalWrite(line3 , LOW);
      digitalWrite(line4 , LOW);
      delay(300);
      break;

      default:
      digitalWrite(line1 , LOW);
      digitalWrite(line2 , LOW);
      digitalWrite(line3 , LOW);
      digitalWrite(line4 , LOW);
       break;
      
    }
  }
//==================================================================

//=====================================================
void operating(){
  int pin_led = 13;
  pinMode(pin_led , OUTPUT);
  digitalWrite(pin_led , HIGH);
  delay(500);
  digitalWrite(pin_led , LOW);
  delay(500);
  }
 void loop() {
  Movement('f');
  operating();
}
