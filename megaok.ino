#include <SPI.h>
#include <RFID.h>
#include <SoftwareSerial.h>
#define SDA_DIO 9
#define RESET_DIO 8
RFID RC522(SDA_DIO, RESET_DIO); 

SoftwareSerial espSerial(5, 6);

String tag = "";
void setup(){ 
  
  Serial.begin(115200);
  espSerial.begin(115200);
  SPI.begin(); 
  RC522.init();
}

String aux="";

void loop()
{
  if (RC522.isCard())
  {
    RC522.readCardSerial();
    for(int i=0;i<5;i++)
    {
   tag+= String(RC522.serNum[i],DEC);
    }
    if(tag != aux){
    //Serial.println(tag);
    espSerial.print(tag);
    }
  }
 tag= "";
 delay(1000);
 aux="";
}
