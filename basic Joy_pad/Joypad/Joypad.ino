#define X_axis A0
#define Y_axis A1
#define Pad_button 7
#define up 8
#define down 9
#define left 10
#define right 11
#define counter 0x0
int number = 0x0;

void setup() {
  pinMode(X_axis , INPUT);
  pinMode(Y_axis , INPUT);
  pinMode(Pad_button, INPUT);

  pinMode(up , OUTPUT);
  pinMode(down , OUTPUT);
  pinMode(left , OUTPUT);
  pinMode(right , OUTPUT);
}

int Read_X(){
  return analogRead(X_axis);
  }
int Read_Y(){
  return analogRead(Y_axis);
  }
int Button_state(){
  return digitalRead(Pad_button);
  }
  

void Movement(){
  digitalWrite(up,LOW);
  digitalWrite(down,LOW);
  digitalWrite(left,LOW);
  digitalWrite(right,LOW);
  switch(Read_Y()){
    case 0:
      digitalWrite(up,HIGH);
      break;
    case 1023:
      digitalWrite(down,HIGH);
      break;
    default:
      break;
    }
  switch(Read_X()){
      case 0:
        digitalWrite(right,HIGH);//
        break;
      case 1023:
        digitalWrite(left,HIGH);
        break;
      default:
        break;
    }
  }


void loop() {
Serial.begin(9600);
Movement();
Serial.println(Button_state());
delay(100);
}
