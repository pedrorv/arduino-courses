#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "Servo.h"

ESP8266WebServer server;

char* ssid = "ssid";
char* password = "password";

Servo motorX;
Servo motorY;

const int xSpeed = 1
        , ySpeed = 1
        , baseX  = 93
        , baseY  = 75
        , xLimit = 23
        , yLimit = 17;

int xAngle = baseX,
    yAngle = baseY;


void setup() {
  motorX.attach(D2);
  motorY.attach(D1);
  motorX.write(baseX);
  motorY.write(baseY);
  
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) { delay(300); }

  Serial.print("\nIP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", [](){
    String html = "<!DOCTYPE html><html lang='en'><head> <meta charset='UTF-8'> <title>Cat the Laser</title></head><body> <button class='mode' id='random'>Random Mode</button> <button class='mode' id='control'>Control Mode</button> <button class='mode' id='pause'>Pause Mode</button> <h1>The game is currently on <span class='mode'>pause</span> mode.</h1> <script> var modes = document.querySelectorAll('.mode'); var currentMode = 'pause'; modes.forEach(function(mode) { mode.addEventListener('click', function() { fetch(location.href + 'change?mode=' + mode.id); currentMode = mode.id; document.querySelector('span.mode').innerHTML = mode.id; }); }); document.addEventListener('keydown', function(event) { if (currentMode === 'control') { fetch(location.href + 'control?move=' + event.key); }  }); </script></body></html>";
    server.send(200, "text/html", html);
  });
  server.on("/control", moveLaser);
  server.begin();
}

void loop() {
  server.handleClient();
}

void moveLaser() {
  String move = server.arg("move");

  if (move == "ArrowDown") {
    if (yAngle + ySpeed <= yAngle + yLimit) {
      yAngle += ySpeed;
      motorY.write(yAngle);
    }
  }
  if (move == "ArrowUp") {
    if (yAngle - ySpeed >= yAngle - yLimit) {
      yAngle -= ySpeed;
      motorY.write(yAngle);
    }
  }
  if (move == "ArrowRight") {
    if (xAngle - xSpeed >= xAngle - xLimit) {
      xAngle -= xSpeed;
      motorX.write(xAngle);
    }
  }
  if (move == "ArrowLeft") {
    if (xAngle + xSpeed <= xAngle + xLimit) {
      xAngle += xSpeed;
      motorX.write(xAngle);
    }
  }

  server.send(200, "text/plain", "ok!");
}
