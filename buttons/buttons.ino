const int ledPin = 13;
const int inputPin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, digitalRead(inputPin));
}
