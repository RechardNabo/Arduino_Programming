#include <SPI.h>
#define RED 0x02
#define GREEN 0x03
#define BLUE 0x04

#define ON 0x01
#define OFF 0x00

#define Analog_Value A0
#define SS 53
void setup() {
  Serial.begin(9600);
  SPI.begin();                //PB2 - PB4 are converted to SS/, MOSI, MISO, SCK
  pinMode(SS, INPUT);
  SPI.setBitOrder(MSBFIRST);  //bit transmission order
  SPI.setDataMode(SPI_MODE1); //
  SPI.setClockDivider(SPI_CLOCK_DIV128);  //data rate = fosc/128 = 125 kbit

}

void loop() {
  digitalWrite(SS,LOW);
   Serial.println("\n=================================");
  int temp_Avg , value;
  value = analogRead(A0);
  SPI.transfer(value);
  Serial.println("\nADC 10-bit Value : "+String(value));
  float voltage = value * (5.0/1024.0);
  Serial.println("Voltage =  "+String(voltage));
  float temperature  =  (voltage-1.375)/0.0225;
  Serial.println("Temperature = "+String(temperature));
  SPI.end();
  delay(500);
}
