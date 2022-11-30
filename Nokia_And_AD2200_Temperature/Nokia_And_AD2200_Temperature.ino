#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#define contrastValue 60
#define TEMPERATURE_PIN A0


//======================== Adafruit_PCD8544(CLK, DIN ,D/C  ,CE   ,RST  );
Adafruit_PCD8544 display = Adafruit_PCD8544(0x02, 0x03, 0x04, 0x05, 0x06);
void setup() {
  Serial.begin(9600);
  SPI.begin();

  SPI.setBitOrder(MSBFIRST);  //bit transmission order
  SPI.setClockDivider(SPI_CLOCK_DIV8);  //data rate = fosc/64 = 125 kbit
  digitalWrite(SS,HIGH);
  display.begin();      
  display.setContrast(contrastValue); //Set contrast to 60
  display.clearDisplay(); 
  display.display();
}

void displayMenu(){
    digitalWrite(SS,LOW);
    int ADC_Value =  analogRead(TEMPERATURE_PIN);
    float Voltage = ADC_Value*(5.0/1024);
    float temp = (Voltage-1.375)/0.0225;
    display.setTextSize(0x01);
    display.clearDisplay();
    display.setTextColor(BLACK, WHITE);
    display.setCursor(8, 0);
    display.print("Temp AD22100");
    display.drawFastHLine(0,10,83,BLACK);
    display.setCursor(0,15);
    display.print("ADC     :"+String(ADC_Value));
    display.setCursor(0, 25);
    display.print("Voltage :"+String(Voltage)+"Voltage");
    display.setCursor(0,35);
    display.print("Tempe   :"+String(temp));
    display.setCursor(0,45);
    display.display();
    SPI.transfer(5);
    Serial.println("Transfer Complete !");
    digitalWrite(SS,HIGH);
    delay(10);
    }
void loop() {

  displayMenu();
}
