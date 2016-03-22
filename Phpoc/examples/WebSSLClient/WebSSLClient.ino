#include "SPI.h"
#include "Phpoc.h"

char server[] = "www.arduino.cc";
//char server[] = "www.google.com";
//char server[] = "www.google.co.kr";

PhpocClient client;

void setup() {
  Serial.begin(115200);
  while(!Serial)
  ;

  Serial.println("PHPoC SSL Client test");

  Phpoc.begin(PF_LOG_SPI | PF_LOG_NET);

  if(client.connectSSL(server, 443)) {
  //if(client.connect(server, 80)) {
    Serial.println("Connected to server");
    // Make a HTTP request:
    client.println("GET /asciilogo.txt HTTP/1.1");
    //client.println("GET / HTTP/1.1");
    client.println("Host: www.arduino.cc");
    //client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();
    Serial.println("Request sent");
  }
}

void loop() {
  // if there are incoming bytes available
  // from the server, read them and print them:
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting from server.");
    client.stop();

    // do nothing forevermore:
    while (true);
  }

}
