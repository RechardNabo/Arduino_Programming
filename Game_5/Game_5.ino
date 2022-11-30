#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>


// configuracoes de hardware
const byte pinoBacklight=9;
const byte potDigital=2;
const byte potAnalogico=A0;
// descritores do jogo: posicao e direcao da bola, posicao e
// largura da raquete, spots, lives
int X=0;
int Y=0;
float aX=1;
float aY=1;
int rY=0;
int rL=15;
long spots=0;
int lives=3;
int velocity=4;

// variaveis auxiliares do jogo
int proxCentena=100;
float Xf=0;
float Yf=0;
int oldX=-1;
int oldY=-1;
int oldrY=-1;
int oldrL=-1;
float oldaX=aX;
float oldaY=aY;
//======================== Adafruit_PCD8544(CLK, DIN ,D/C  ,CE   ,RST  );
Adafruit_PCD8544 display = Adafruit_PCD8544(0x02, 0x03, 0x04, 0x05, 0x06); 

void setBacklight(byte intensidade) {
  analogWrite(pinoBacklight,intensidade);
}  

void setup(){
  Serial.begin(9600);
  setBacklight(80);
  pinMode(pinoBacklight,OUTPUT);
  pinMode(potDigital,OUTPUT);
  digitalWrite(potDigital,HIGH);
  randomSeed(analogRead(potAnalogico));
  gameStart();
  display.setContrast(60);
  display.clearDisplay(); 
  display.setTextSize(0x01);

  //gameOver();
}

void posicionaBolaXY() {  
// apaga a bola da posicao anterior e desenha na atual
  if (oldX>=0)   display.drawRect(oldX,oldY,4,4,WHITE);
  display.drawRect(X,Y,4,4,BLACK);
  oldX=X;
  oldY=Y;
}  

void posicionaRaqueteYL() {  
// apaga a raquete da posicao anterior e desenha na atual
  if (oldrY>=0)   display.drawRect(78,oldrY,2,oldrL,WHITE);  
  display.drawRect(78,rY,2,rL,BLACK);
  oldrY=rY;
  oldrL=rL;
}  

void atualizaPlacares() {  
// informa na tela o numero de lives e os spots
  display.fillRect(0,40,70,8,WHITE);
  display.setCursor(44,40);
  display.print("P:"+String(spots));
  display.setCursor(1,40);
  display.print("Livs:"+String(lives));
}

void gameStart(){
  display.begin();
  display.setContrast(30); //Set the contrast of the display
  display.clearDisplay(); 
  display.setTextSize(0x01);
  display.clearDisplay();
  display.setTextColor(BLACK, WHITE);
  display.setCursor(13, 0);
  display.print(" Starting");
  display.drawFastHLine(0,10,83,BLACK);
  display.setCursor(0,15);  
  display.setTextSize(2);      
  display.setTextColor(BLACK);
  display.setCursor(10,12);
  display.print("Bounce\n Ball");
  display.setCursor(10,50);
  display.print("utopian");
  display.display();
  delay(4000);
}

void gameOver() {  
// tela que aguarda o inicio de nova partida, e a inicializa
  display.clearDisplay();
  display.setTextSize(2);  
  display.setCursor(10,0);
  display.print("GAME");
  display.setCursor(30,17);
  display.print("OVER");
  display.setTextSize(1);
  display.setCursor(8,32);
  display.print("Press Anykey!");  
  lives=0;
  atualizaPlacares();  
  display.display();
  int a=analogRead(potAnalogico);
  while(abs(a-analogRead(potAnalogico))<=100) {
    delay(50);
  }  
  spots=0;
  lives=3;
  velocity=4;
  X=0;
  Y=0;
  aX=1;
  aY=1;
  rY=0;
  rL=15;  
  display.clearDisplay();
  atualizaPlacares();
}  

void piscaTela() {
  for (int p=0; p<=6; p++) {
    setBacklight(250);
    delay(140);
    setBacklight(25);
    delay(60);
  }  
}

void detectaBatidas() {
  oldaX=aX;
  oldaY=aY;
  if (X==0) aX=1;
  if (Y==36) aY=-1;
  if (Y==0) aY=1;  
  if (X==76) {
    // verifica se bateu na raquete e prossegue, reduz as 
    // lives ou encerra, conforme o caso
    if ((Y>=rY-3) & (Y<=rY+rL)) { 
      aX=-0.65+random(0,90)/100;
      spots+=10;
      gerenciaFases(); 
      setBacklight(200);    
    } else {
      lives--;
      Xf=0;   
      piscaTela();
      atualizaPlacares();  
     if (lives<0) {
       gameOver();
     }  
    }  
  }  
}

void moveRebateBola() {
  setBacklight(10+X*0.8);
  Xf=Xf+aX;
  Yf=Yf+aY;
  X=int(Xf);
  Y=int(Yf);
  if ((oldaY!=aY) | (oldaX!=aX)) {
    spots++;
    atualizaPlacares();   
    gerenciaFases(); 
  }  
}

void moveRaquete() {
  int potLido=analogRead(potAnalogico);
  if (potLido<448) potLido=448;
  if (potLido>576) potLido=576;  
  rY=map(potLido,448,576,40-rL,0);
}

void gerenciaFases() {
  if (spots>proxCentena) {
    if ((proxCentena % 500)==0) lives++;
    if (rL>4) rL-=2;
    if (velocity<8) velocity++;
    proxCentena+=100;
  }  
}

void loop() {
  posicionaRaqueteYL();
  posicionaBolaXY();
  delay(10-velocity);
  detectaBatidas();
  moveRebateBola();
  moveRaquete();
  display.display(); 
}
