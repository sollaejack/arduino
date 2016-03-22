#include "SPI.h"
#include "Phpoc.h"

PhpocServer server(80);

char slideName;
int slideValue;

void setup() {
  Serial.begin(115200);
  while(!Serial)
    ;

  //Phpoc.begin(PF_LOG_SPI | PF_LOG_NET);
  Phpoc.begin();
  server.beginWebSocket("remote_slide");

  Serial.print("WebSocket server address : ");
  Serial.println(Phpoc.localIP());  
}

void loop() {
  // wait for a new client:
  PhpocClient client = server.available();

  if (client) {
    String slideStr = client.readLine();

    if(slideStr)
    {
      slideName = slideStr.charAt(0);
      slideValue = slideStr.substring(1).toInt();

      Serial.print(slideName);
      Serial.print('/');
      Serial.println(slideValue);
    }
  }
}
