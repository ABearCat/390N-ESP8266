#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Adafruit_NeoPixel.h>
#include "html_homepage.h"

#define PIN_BUTTON   0
#define PIN_LED     15
#define PIN_BUZZER  13


// create pixel object
Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, PIN_LED, NEO_GRB + NEO_KHZ800);
ESP8266WebServer server(80);

void on_homepage(){
  String html = FPSTR(html_homepage);
  server.send(200, "text/html", html);
}

void setup() {
  pixel.begin();
  pixel.show();

  WiFi.mode(WIFI_AP);
  String ap_name = "Group 14";
  WiFi.softAP(ap_name.c_str());

  server.on("/", on_homepage);
  server.begin();
}

void loop() {
  server.handleClient();
}
