#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server;

char* ssid = "ssid";
char* password = "password";

void setup() {
  pinMode(D2, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D0, OUTPUT);
  
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) { delay(300); }

  Serial.print("\nIP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", [](){
    String html = "<!DOCTYPE html> <html lang='en'> <head> <meta charset='UTF-8'> <meta name='viewport' content='width=device-width, initial-scale=1.0'> <meta http-equiv='X-UA-Compatible' content='ie=edge'> <title>WS Led</title> </head> <body> <button class='led' id='red'>Toggle Red</button> <button class='led' id='yellow'>Toggle Yellow</button> <button class='led' id='green'>Toggle Green</button> <script> var leds = document.querySelectorAll('.led'); leds.forEach(function(element) { element.addEventListener('click', function() { fetch(location.href + 'toggle?color=' + element.id); }); }); </script> </body> </html>";
    server.send(200, "text/html", html);
  });
  server.on("/toggle", toggleLED);
  server.begin();
}

void loop() {
  server.handleClient();
}

void toggleLED() {
  String color = server.arg("color");
  String message = "";

  if (color == "red") {
    digitalWrite(D2, !digitalRead(D2));
    message += "Toggled the red led!";
  }
  else if (color == "yellow") {
    digitalWrite(D1, !digitalRead(D1));
    message += "Toggled the yellow led!";
  }
  else if (color == "green") {
    digitalWrite(D0, !digitalRead(D0));
    message += "Toggled the green led!";
  } else {
    message += "Unknown color.";
  }
  
  server.send(200, "text/plain", message);
}
