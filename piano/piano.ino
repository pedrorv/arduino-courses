const int ledPin1 = 13;
const int ledPin2 = 12;
const int ledPin3 = 11;
const int Button1 = 2;
const int Button2 = 3;
const int Button3 = 4;
const int Buzzer = 10;
int StateButton1 = 0;
int StateButton2 = 0;
int StateButton3 = 0;

void setup() {
  pinMode(Buzzer, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(Button1, INPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(Button2, INPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(Button3, INPUT);
}

void loop() {
  StateButton1 = digitalRead(Button1);
  StateButton2 = digitalRead(Button2);
  StateButton3 = digitalRead(Button3);
  if(StateButton1 && !StateButton2 && !StateButton3) {
    digitalWrite(ledPin1, HIGH);
    tone(Buzzer, 100);
  }
  if(StateButton2 && !StateButton1 && !StateButton3) {
    digitalWrite(ledPin2, HIGH);
    tone(Buzzer, 500);
  }
  if(StateButton3 && !StateButton2 && !StateButton1) {
    digitalWrite(ledPin3, HIGH);
    tone(Buzzer, 1000);
  }
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  noTone(Buzzer);
}
