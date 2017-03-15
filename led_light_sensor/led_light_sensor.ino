const int LDR = 0;
const int Led = 6;
int valueRead = 0;
int pwm = 0;

void setup() {
  pinMode(Led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  valueRead = analogRead(LDR);

  Serial.println(valueRead);

  if (valueRead < 500) {
    analogWrite(Led, pwm);
    pwm++;
    delay(100);  
  } else {
    digitalWrite(Led, LOW);
    pwm = 0;  
  }

  if (pwm > 255) {
    pwm = 255;
  }
}
