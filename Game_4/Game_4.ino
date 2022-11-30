#include <LCD5110_Graph.h>
#include <avr/pgmspace.h>

#define RST 0x06    // RESET
#define CE  0x05    // CS
#define DC  0x04    // Data/Command
#define DIN  0x03   // MOSI
#define CLK  0x02    // SCK

// LCD5110(SCK, MOSI, DC, RST, CS);
LCD5110 display(CLK, DIN, DC, RST, CE); 

extern uint8_t SmallFont[];

const uint8_t pacman1[] PROGMEM={
0x80, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7E, 0x3E, 0x1C,   // 0x0010 (16) pixels
0x0C, 0x00, 0x00, 0x00, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9,   // 0x0020 (32) pixels
0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0F,   // 0x0030 (48) pixels
0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x03, 0x00, 0x00, 0x00,
};

const uint8_t pacman2[] PROGMEM={
0x80, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0x7C,   // 0x0010 (16) pixels
0x7C, 0x38, 0x20, 0x00, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9,   // 0x0020 (32) pixels
0xF9, 0xF0, 0xF0, 0xE0, 0xE0, 0xC0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0F,   // 0x0030 (48) pixels
0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00,
};

const uint8_t pacman3[] PROGMEM={
0x80, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFC,   // 0x0010 (16) pixels
0xF8, 0xF0, 0xE0, 0x80, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,   // 0x0020 (32) pixels
0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xF9, 0x79, 0x19, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0F,   // 0x0030 (48) pixels
0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00,
};

const uint8_t pill[] PROGMEM={
0x0E, 0x1F, 0x1F, 0x1F, 0x0E,
};
#define Width  84
#define Hight  48
#define Range  12

int FirstShotX , FirstShotY;
int PointX, PointY;
int delaytime;

void setup()
{
  /* Init LCD5110_Graph library */
  display.InitLCD();
  display.setFont(SmallFont);
  randomSeed(analogRead(0));

  /* Record Joystick corrected coordinates */
  FirstShotX = analogRead(A0);
  FirstShotY = analogRead(A1);

  /* Black specks the initial coordinates */
  PointX = 75;
  PointY = 20;

  /* Refresh time */
  delaytime = 50;

  /* Start display */
  display.print("- Viral Science -", CENTER, 0);
  display.print("PACMAN", CENTER, 20);
  display.print("Arduino", CENTER, 40);
  display.update();
  delay(3000);

  /* Init Serial port */
  Serial.begin(115200);
}

void loop()
{
  //int pacy=random(0, 42);
  uint8_t* bm;

  for (int i=-20; i<84; i++)
  {
    // Clear LCD
    display.clrScr();

    // Refresh Greedy Freak Bitmap
    switch(((i+20)/3) % 4)
    {
      case 0: bm=pacman1;
              break;
      case 1: bm=pacman2;
              break;
      case 2: bm=pacman3;
              break;
      case 3: bm=pacman2;
              break;
    }
    int sensorValueX = (analogRead(A0) - FirstShotX)*0.1 + 32;        //You can change the coefficient such as 0.08, which decide X-axis Range
    int sensorValueY = (FirstShotY - analogRead(A1))*0.06 + 14;       //You can change the coefficient such as 0.04, which decide Y-axis Range

    display.drawBitmap(sensorValueX, sensorValueY, bm, 20, 20);
    // Once the Greedy Freak be close to black specks, random another X and Y
TX:
    if((sensorValueX-5 <= PointX && PointX <= sensorValueX+15) && (sensorValueY-3 <= PointY && PointY <= sensorValueY + 20))
    {
       PointX = random(0, 80);
       PointY = random(0, 43);
       goto TX;
    }
    else
      display.drawBitmap(PointX, PointY, pill, 5, 5);

//    display.update();        // update and display the Bitmap

    int j, someInt, flag = 0;
    for(j=2; j<9; j++)
    {
      someInt = digitalRead(j);        // scan the KEY (check for pressed button)
      if(someInt == 0)
      {
        flag = 1;
        break;
      }
     }
     if(flag == 1)
     {
       Serial.println(i);
       switch(j)
       {
         case 2: Serial.println("--------> Button A");
                 delaytime = 50;
                 display.invert(true);
                 break;
         case 3: Serial.println("--------> Button B");
                 delaytime = 50;
                 display.invert(false);
                 break;
         default: break;
       }
       flag=0;
     }
    delay(delaytime);
    display.update();        // update and display the Bitmap
  }
}
