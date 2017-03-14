const int LM35 = 0;
float temperature = 0;
int ADCread = 0;
const int Buzzer = 12;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  ADCread = analogRead(LM35);
  temperature = ADCread * 0.1075268817;
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.print(" ºC\n");

  if (temperature > 31.5) {
    tone(Buzzer, 2000);
  } else {
    noTone(Buzzer);
  }
  delay(1000);
}
