#define pin_detect 8

void setup() {
pinMode(pin_detect,INPUT);
}

void counter(){
  Serial.begin(9600);
  int counter = 1;
  while(true){
  delay(200);
  int state = digitalRead(pin_detect);
  if(state==1){
    counter=counter+1;
    if(counter>=3){
      counter=3;
      }
    Serial.println("Power ON");
    }
    Serial.println(counter);
    }
  }
void loop() {
  counter();
}
