#include <SPI.h>
#include <Phpoc.h>

PhpocDateTime datetime;

void setup() {
  Serial.begin(115200);
  while(!Serial)
    ;
    
  Phpoc.begin(PF_LOG_SPI | PF_LOG_NET | PF_LOG_EMAIL);
  //Phpoc.begin();
  
  Serial.println("Phpoc Time test");
  
  Serial.print(datetime.year());
  Serial.print('-');
  Serial.print(datetime.month());
  Serial.print('-');
  Serial.print(datetime.day());
  Serial.print(' ');
  Serial.print(datetime.dayofWeek());
  Serial.print(':');
  Serial.print(datetime.hour());
  Serial.print(':');
  Serial.print(datetime.minute());
  Serial.print(':');
  Serial.print(datetime.second());
  Serial.println();

  datetime.date("Y-m-d H:i:s");
}

void loop() {
  Serial.println(datetime.date());
  delay(1000);
}
