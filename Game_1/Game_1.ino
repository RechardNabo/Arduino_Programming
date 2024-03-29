#include <EEPROM.h>
#include <SPI.h>
//#include <GR_Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

/********* constants *******/
#define L_R A0    // joystick horizontal movement
#define U_D A1    // joystick vertical movement
#define PAUSE 53
#define MAX_WIDTH 84        //display 84x48
#define MAX_HEIGHT 48
#define speakerPin 2

boolean dl=false,dr=false,du=false,dd=false;   // to check in which direction the snake is currently moving

int x[200],y[200],i,slength,tempx=10,tempy=10,xx,yy;
unsigned int high=0;
uint8_t bh,bl;
int xegg,yegg;
int freq,tb;
int l,r,u,d,p,l_r,u_d;
unsigned long time=280,beeptime=50;
int score=0,flag=0;


//======================== Adafruit_PCD8544(CLK, DIN ,D/C  ,CE   ,RST  );
Adafruit_PCD8544 display = Adafruit_PCD8544(0x02, 0x03, 0x04, 0x05, 0x06); 


void setup()
{
  Serial.begin(9600);         //Begin Serial Communication
  EEPROM.write(1,0); //Use only the first time
  EEPROM.write(0,0); //you install the program
  
  pinMode(L_R,INPUT);         //Directional keys and pause
  pinMode(U_D,INPUT);
  pinMode(PAUSE,INPUT);
  pinMode(speakerPin,OUTPUT);  //Buzzer pin
  digitalWrite(PAUSE,HIGH);    //Active low key
  
  slength=8;                 //Start with snake length 8
  xegg=(display.width())/2;  
  yegg=(display.height())/2;
  
  display.begin();
  display.clearDisplay();
  display.setContrast(25);
  display.setTextSize(0x01);
  display.clearDisplay();
  display.setTextColor(BLACK, WHITE);
  display.setCursor(13, 0);
  display.print(" Starting");
  display.drawFastHLine(0,10,83,BLACK);
  display.setCursor(0,15); 
  display.setTextSize(2);          //Initial Display
  display.setTextColor(BLACK);
  display.setCursor(10,15);
  display.print("SNAKE");
  display.display();
  delay(4000);
  display.clearDisplay();
  
  for(i=0;i<=slength;i++)      //Set starting coordinates of snake
  {
    x[i]=25-3*i;
    y[i]=10;   
  }
  
  for(i=0;i<slength;i++)         //Draw the snake
     {
     display.drawCircle(x[i],y[i],1,BLACK);
     }
     display.display();

dr=true;    //Going to move right initially
}


//Movement Begins after here
void loop()   
{
     
   
   movesnake();    //This is called endlessly
     
}

 
void movesnake()
{
  l=1;
  r=1;
  u=1;
  d=1;
  l_r=analogRead(L_R);      //Continuously Check Joystick & pause Key
  u_d=analogRead(U_D);
  p=digitalRead(PAUSE);
  if (l_r > 700) {l = LOW;}
  else if (l_r <300) {r = LOW;}
  if (u_d > 700) {d = LOW;}
  else if (u_d < 300){u = LOW;}

if(flag==0)
{
direct();    //When key is pressed,this will change the coordinates accordingly and set flag to 1 
             //flag would be set to 1 so that direction is not changed multiple times in a short duration
}




  if(millis()%time==0)     //this condition becomes true after every 'time' milliseconds...millis() returns the time since launch of program
{
       
       
     if(flag==0)                                   //flag 0 means no directional key has been pressed in the last 'time' milliseconds
     {
       if(dr==true){tempx=x[0]+3;tempy=y[0];}      // so the snake moves one step in the direction it is moving currently
       if(dl==true){tempx=x[0]-3;tempy=y[0];}      //The new coordinates of head of snake goes in tempx,tempy
       if(du==true){tempy=y[0]-3;tempx=x[0];}
       if(dd==true){tempy=y[0]+3;tempx=x[0];}
     }
   
   flag=0;  
     checkgame();                              //Check if snake has met egg or coincided with itself
      checkegg();
      
 if(tempx<=0){tempx=84+tempx;}     //If the new coordinates are out of screen, set them accordingly
 if(tempx>=84){tempx=tempx-84;}
 if(tempy<=0){tempy=48+tempy;}
 if(tempy>=48){tempy=tempy-48;}

 for(i=0;i<=slength;i++)        //Change the coordinates of all points of snake
  {
   xx=x[i];
   yy=y[i]; 
   x[i]=tempx;
   y[i]=tempy;
   tempx=xx;
   tempy=yy;
  }
  
drawsnake();           //Draw the snake and egg at the new coordinates
}
}


void checkgame()       //Game over checker
{
  for(i=1;i<slength;i++)               //Checking if the coordinates of head have become equal to one of the non head points of snake
  {
    if(x[i]==x[0] && y[i]==y[0])
    {
      
      bh=EEPROM.read(1);
      bl=EEPROM.read(0);
 /*     high=(((0xff00+bh)<<8) + bl); */
      high = (((0x0000 + bh)<<8) + bl);
      if(score>high)
      {
        high=score;
        bl=high & 0xff;       
        bh=(high >> 8);
        
        EEPROM.write(1,bh);
        EEPROM.write(0,bl);
      }
      
      display.clearDisplay();
      display.setTextColor(BLACK);       
      display.setTextSize(1);
      display.setCursor(20,12);
      display.print("Game Over");
      display.setCursor(15,30);
      display.print("Score: ");
      display.print(score);
      display.setCursor(15,40);
      display.print("High: ");
      display.print(high);
      
      display.display();
      beep(20,5000);
      
      
      display.clearDisplay();
      
      slength=8;              //Resetting the values
      score=0;
      time=280;
      
      redraw();              //Restart game by drawing snake with the resetted length and score
    }
  }

}

void checkegg()      //Snake meets egg
{
  if(x[0]==xegg or x[0]==(xegg+1) or x[0]==(xegg+2) or x[0]==(xegg-1))      //Snake in close vicinity of egg
  {
    if(y[0]==yegg or y[0]==(yegg+1) or y[0]==(yegg+2) or y[0]==(yegg-1))
    {
      score+=1;                       //Increase length,score and increase movement speed by decreasing 'time'
      slength+=1;
      if(time>=90)
      {time-=20;}
      
      display.fillRect(xegg,yegg,3,3,WHITE);      //Delete the consumed egg
      
      display.display();
      
      
      beep(35,beeptime);              //Beep with a sound of 35Hz for 'beeptime' ms
      xegg=random(1,80);              //Create New egg randomly
      yegg=random(1,40);
    }
  }
}  
     
      
void direct()                  //Check if user pressed any keys and change direction if so
{
  if(l==LOW and dr==false)       //when key LEFT is pressed ,L will become low
  {
    dl=true;du=false;dd=false;
    tempx=x[0]-3;                //Save the new coordinates of head in tempx,tempy
    tempy=y[0];
    flag=1;                     //Do not change direction any further for the ongoing 'time' milliseconds
  }  
  else if(r==LOW and dl==false)
  {
    dr=true;du=false;dd=false;
    tempx=x[0]+3;
    tempy=y[0];
    flag=1;
  }  
  else if(u==LOW and dd==false)
  {
    du=true;dl=false;dr=false;
    tempy=y[0]-3;
    tempx=x[0];
    flag=1;
  }  
  else if(d==LOW and du==false)
  {
    dd=true;dl=false;dr=false;
    tempy=y[0]+3;
    tempx=x[0];
    flag=1;
  } 
  else if(p==LOW)               //Pause game for 5 seconds
  {
  display.clearDisplay();
  
  display.setTextColor(BLACK);
  for(i=5;i>0;i--)
    {
     display.setCursor(25,10); 
     display.setTextSize(1);
     display.print("PAUSED");
     display.setCursor(40,30);
     display.print(i);
     display.display();
     delay(1000);
     display.clearDisplay();
    } 
    redraw();          //Redraw the snake and egg at the same position as it was 
  } 
}


void drawsnake()        //Draw snake and egg at newly changed positions
{
  display.fillRect(xegg,yegg,3,3,BLACK);       //Draw egg at new pos
  
  display.drawCircle(x[0],y[0],1,BLACK);       //Draw new head of snake
  display.drawCircle(x[slength],y[slength],1,WHITE);   //Delete old tail of snake
  
  display.display();
        
}

void redraw()   //Redraw ALL POINTS of snake and egg
{
  display.fillRect(xegg,yegg,3,3,BLACK);
  for(i=0;i<slength;i++)
     {
     display.drawCircle(x[i],y[i],1,BLACK);
     
     }
     display.display();
}     
     
     
     
void beep (int freq,long tb)           //This function creates a sound of frequency 'freq' Hz and for a duration of 'tb' milliseconds
{ 
    int x; 	 
    long delayAmount = (long)(500/freq);       //Calculate time duration of half cycle
    long loopTime = (long)(tb/(delayAmount*2));   //Calculate no. of cycles
    for (x=0;x<loopTime;x++) 	 // One iteration produces sound for one cycle
    { 	 
        digitalWrite(speakerPin,HIGH);   //High for half cycle
        delay(delayAmount);
        digitalWrite(speakerPin,LOW);    //Low for half cycle
        delay(delayAmount);
    } 	 
    
    delay(2);
    //a little delay to make all notes sound separate
}      

   
  
  
  
