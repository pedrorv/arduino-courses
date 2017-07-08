#include "Servo.h"

Servo motorX;
Servo motorY;
const int X = 10;
const int Y = 9;
const int servoDelay = 15;
int direction;
int xAngle = 93;
int yAngle = 75;
int xSpeed = 1;
int ySpeed = 1;

void setup() {
  motorX.write(93);
  motorY.write(75);
  motorX.attach(X);
  motorY.attach(Y);
  delay(2000);
}

void loop() {
  direction = random(2);
  
  if (direction == 0) {
    xAngle += xSpeed;
    motorX.write(xAngle);

    if (xAngle > (93 + 22)) {
      xSpeed = -xSpeed;
    }
    if (xAngle < (93 - 22)) {
      xSpeed = -xSpeed; 
    }
  }
  else if (direction == 1) {
    yAngle += ySpeed;
    motorY.write(yAngle);

    if (yAngle > (75 + 17)) {
      ySpeed = -ySpeed;
    }
    if (yAngle < (75 - 17)) {
      ySpeed = -ySpeed; 
    }
  }

  delay(servoDelay);
}
