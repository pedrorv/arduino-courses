const int LM35 = 0;
float temperature = 0;
int ADCread = 0;
const int Buzzer = 12;
const int LED[] = {2,3,4,5,6,7,8,9,10,11};

void setup() {
  analogReference(INTERNAL);
  pinMode(Buzzer, OUTPUT);
  for(int x = 0; x < 10; x++){
    pinMode(LED[x], OUTPUT);
  }

  Serial.begin(9600);
}
void loop() {
  ADCread = analogRead(LM35);
  temperature = ADCread * 0.1075268817204301;

  Serial.println(temperature);

  for (int i = 0; i < 10; i++) {
    if (temperature > (25.0 + i * 0.5)) {
      digitalWrite(LED[i], HIGH);
      if (i == 9) tone(Buzzer, 2000);
    }
    else {
      digitalWrite(LED[i], LOW);
      if (i == 9) noTone(Buzzer);
    }
  }
  delay(1000);
}
