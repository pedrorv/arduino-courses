const int LM35 = 0;
float temperature = 0;
int ADCread = 0;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);
}

void loop() {
  ADCread = analogRead(LM35);
  temperature = ADCread * 0.1075268817;
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.print(" ºC\n");
  delay(1000);
}
