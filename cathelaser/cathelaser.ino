#include "Servo.h"

Servo motorX;
Servo motorY;
const int X = 10
        , Y = 9
        , servoDelay = 15
        , xBaseAngle = 93
        , yBaseAngle = 75
        , xLimit = 23
        , yLimit = 17;

int direction
  , xAngle = xBaseAngle
  , yAngle = yBaseAngle
  , xSpeed = 1
  , ySpeed = 1;

void setup() {
  motorX.write(xBaseAngle);
  motorY.write(yBaseAngle);
  motorX.attach(X);
  motorY.attach(Y);
  delay(2000);
}

void loop() {
  direction = random(2);
  
  if (direction == 0) {
    xAngle += xSpeed;
    motorX.write(xAngle);

    if (xAngle > (xBaseAngle + xLimit) || xAngle < (xBaseAngle - xLimit)) {
      xSpeed = -xSpeed;
    }
  }
  
  if (direction == 1) {
    yAngle += ySpeed;
    motorY.write(yAngle);

    if (yAngle > (yBaseAngle + yLimit) || yAngle < (yBaseAngle - yLimit)) {
      ySpeed = -ySpeed;
    }
  }

  delay(servoDelay);
}
