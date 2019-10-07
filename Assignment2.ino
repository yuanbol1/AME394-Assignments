#include <Arduino.h>
#include <TTGO.h>
TTGOClass *ttgo;


char * HOSTNAME = "test12345678";
char * WifiPASS = "12345678";

#include <WiFi.h>
#include <WebServer.h>



WebServer server(80);


void setup() {
    Serial.begin(115200);
    ttgo = TTGOClass::getWatch();
    ttgo->begin();
    ttgo->openBL();

    ttgo->eTFT->fillScreen(TFT_BLACK);
    ttgo->eTFT->setTextColor(TFT_WHITE, TFT_BLACK);
    ttgo->eTFT->setTextFont(4);
 
    pinMode(21, OUTPUT);




    

    // Start Wifi AP
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAP(HOSTNAME, WifiPASS);


    
    // handle index -- HTTP Server

    
    server.on("/on", []() {
      digitalWrite(21, 1);
      server.send(200, "text/html", "<html><head></head><body><a href=\"./on\">on</a><br><a href=\"./off\">off</a></body><html>");
      ttgo->eTFT->drawString("Hi",  65, 110);
    });

    server.on("/off", []() {
      digitalWrite(21, 0);
      server.send(200, "text/html", "<html><head></head><body><a href=\"./on\">on</a><br><a href=\"./off\">off</a></body><html>");
     });

 
    server.on("/", []() {
      server.send(200, "text/html", "<html><head></head><body><a href=\"./on\">on</a><br><a href=\"./off\">off</a></body><html>");
    });

    
    server.begin();
    
}

void loop() {
    server.handleClient();
}
