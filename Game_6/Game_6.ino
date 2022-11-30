#include <SPI.h> 
#include <Adafruit_GFX.h> 
#include <Adafruit_PCD8544.h> 
#define CONTROLLER A0 

int enemy_0_posCart, enemy_1_posCart, enemy_phase;
int Joy_X;
int game_speed = 0;
int line_height1 = 5;
int score = 0;
char posCart=2;
boolean enemy_dead = true;

static const unsigned char PROGMEM cart[] =
{
B00011111,B11110000,
B00011111,B11110000,
B01111001,B00111100,
B01111001,B00111100,
B01111001,B00111100,
B00011011,B10110000,
B00011000,B00110000,
B00011000,B00110000,
B00011010,B10110000, 
B01111010,B10111100,
B01111011,B10111100,
B01111000,B00111100,
B00011111,B11110000,
B00011111,B11110000,
B00000000,B00000000,
};
 
static const unsigned char PROGMEM cactus[] =
{
B01110011,B11001110,
B01110011,B11001110,
B01111111,B11111110,
B01111111,B11111110,
B01110011,B11001110,
B01110011,B11001110,
B00000011,B11000000,
B00000011,B11000000,
B00000011,B11000000,
B01110011,B11001110,
B01110011,B11001110,
B01111111,B11111110,
B01111111,B11111110,
B01110011,B11001110,
B01110011,B11001110,
};
 
static const unsigned char PROGMEM line[] =
{
B11000000,
B11000000,
B11000000,
B11000000,
B11000000,
B11000000,
B11000000,
B11000000,
B11000000,
B11000000,
B11000000,
B11000000,
B11000000,
B11000000,
};
 
static const unsigned char PROGMEM jerry[] ={
0x0,0x7,0x0,0x0,
0x0,0xF,0x80,0x0,
0x0,0xF,0x80,0x0,
0x0,0x7,0x0,0x0,
0x0,0x7,0x0,0x0,
0x0,0xF,0x80,0x0,
0x0,0x1F,0xC0,0x0,
0x2,0x3F,0xE2,0x0,
0x7,0x40,0x17,0x0,
0x6,0x80,0xB,0x0,
0x7,0x84,0x8F,0x0,
0x7,0x8D,0x8F,0x0,
0x7,0x80,0xF,0x0,
0x3,0x80,0xE,0x0,
0x0,0x88,0x88,0x0,
0x0,0x47,0x10,0x0,
0x0,0xB0,0x68,0x0,
0x1,0x10,0x44,0x0,
0x2,0x10,0x42,0x0,
0x4,0x3F,0xE1,0x0,
0x4,0x37,0x61,0x0,
0x4,0xFA,0xF9,0x0,
0x4,0xFD,0xF9,0x0,
0x7,0xFA,0xFF,0x0,
0xF,0xF7,0x7F,0x80,
0xF,0xFF,0xFF,0x80,
0x4,0xFF,0xF9,0x0,
0x3,0xFF,0xFE,0x0,
0x3,0xF8,0xFE,0x0,
0x3,0xF8,0xFE,0x0,
0x3,0xF8,0xFE,0x0,
0x0,0x0,0x0,0x0,
};
 
 
//======================== Adafruit_PCD8544(CLK, DIN ,D/C  ,CE   ,RST  );
Adafruit_PCD8544 display = Adafruit_PCD8544(0x02, 0x03, 0x04, 0x05, 0x06); 

 
 
void setup()   {
  Serial.begin(9600); 
 
  pinMode(CONTROLLER,INPUT);
 
  display.begin(); 
  display.setContrast(30); 
  display.clearDisplay();   
  Start();
  screenStart();
}
 
void loop() {
  
 
  display.clearDisplay();   
  
 
  gameScreen(); 
  controler();
 
display.display();  
 
}
 
void controler()
{ 
    
    if (analogRead(CONTROLLER) <= 200) 
    {
      posCart--;   
      if (posCart<1) posCart=1;
    }
    
    else if (analogRead(CONTROLLER) >= 800)
    {
      posCart++;   
      if (posCart>3) posCart=3;
    }
 
 
  player_car(posCart); 
 
  if (enemy_dead) 
  { 
  enemy_0_posCart = posCart;
  enemy_1_posCart = random(0,4);
  enemy_phase = 0; 
  enemy_dead = false; 
  }
 
  enemy_ship (enemy_0_posCart,enemy_phase); enemy_phase++; 
  enemy_ship (enemy_1_posCart,enemy_phase); enemy_phase++; 
   
  line_height1++;
  
  if (enemy_phase>22 && ((enemy_0_posCart == posCart) || (enemy_1_posCart == posCart)) ) 
  game_over(); 
  
  if (enemy_phase>40) 
  {enemy_dead = true; score++;} 
 
  Level(); //BAsed on score increase the speed of game
}
  
  
 
void   Level() 
{ 
  if (score>=0 && score<=10) 
  {
    game_speed = 0; delay(45);
  }
    if (score>10 && score<=20) 
  {
    game_speed = 1; delay(40); 
  }
    if (score>20 && score<=30) 
  {
    game_speed = 2; delay(35); 
  }
    if (score>30 && score<=40) 
  {
    game_speed = 3; delay(30); 
  }
  if (score>40 && score<=50) 
  {
    game_speed = 4; delay(25); 
  }
  if (score>50 && score<=60) 
  {
    game_speed = 5; delay(20); 
  }
  if (score>60 && score<=70) 
  {
    game_speed = 6; delay(15); 
  }
  if (score>80 && score<=90) 
  {
    game_speed = 7; delay(10); 
  }
  if (score>100 && score<=110) 
  {
    game_speed = 8; delay(5); 
  }
  if (score>110 && score<=120) 
  {
    game_speed = 9; delay(0); 
  }
}
 
void enemy_ship(int place, int phase) 
{
  if (place==1)
  display.drawBitmap(9, phase, cactus, 15, 15, BLACK);
 
  if (place==2)
  display.drawBitmap(34, phase, cactus, 15, 15, BLACK);
 
  if (place==3)
  display.drawBitmap(60, phase, cactus, 15, 15, BLACK);
}
 
void game_over() 
{
  while(1) 
  {
    delay(100);
  display.clearDisplay();
  display.setTextSize(2);  
  display.setCursor(15,5);
  display.println("GAME   OVER");
  display.setTextSize(1); 
  display.setCursor(20,40);
  display.println("score:");
  display.setCursor(57,40);
  display.println(score);
  
  display.display();  
  
  Serial.print(score);
  }
}
 
void gameScreen()
{
 
      display.drawLine  (2, 0, 2, 48, BLACK);
      display.drawLine  (3, 0, 3, 48, BLACK);
      display.drawLine  (4, 0, 4, 48, BLACK);
      display.drawLine  (80, 0, 80, 48, BLACK);
      display.drawLine  (81, 0, 81, 48, BLACK);
      display.drawLine  (82, 0, 82, 48, BLACK);
 
      display.drawBitmap(27,line_height1,line, 2, 15, BLACK);
      display.drawBitmap(53,line_height1,line, 2, 15, BLACK);
      
      line_height1++;
      if (line_height1>52) line_height1 = -5;
      if (line_height1>40) line_height1 = -5;
        Serial.println(line_height1);
}
 
void player_car(char posCart) 
{
  if (posCart==1)
  display.drawBitmap(9, 32, cart, 15, 15, BLACK);
 
  if (posCart==2)
  display.drawBitmap(34, 32, cart, 15, 15, BLACK);
 
  if (posCart==3)
  display.drawBitmap(60, 32, cart, 15, 15, BLACK);
}
 
void screenStart()
{
  if(score==0){
      score++;
      display.setTextSize(2);
      display.setCursor(37,20);
      display.println("3");
      display.display();
      delay(500);
      display.clearDisplay();
      display.setCursor(37,20);
      display.println("2");
      display.display();
      delay(500);
      display.clearDisplay();
      display.setCursor(37,20);
      display.println("1");
      display.display();
      delay(500);
      display.clearDisplay();
      display.setCursor(25,20);
      display.println("GO!!");
      display.display();
      delay(500);
      display.clearDisplay();
      
    }
}
void Start()
{
   
 
  display.drawBitmap( 27, 3,  jerry, 31, 31, 1); 
 
  display.setTextSize(1);                   
  display.setTextColor(BLACK);              
  display.setCursor(8,37);                   
  display.print("ForbiddenBit");
 
  display.display();
  delay(1000);
  display.clearDisplay();
  
}