void setup() {
  Serial.begin(9600);
  pinMode(5,OUTPUT);
}

void Blink(int t=300)
{
    digitalWrite(5,HIGH);
    delay(t);
    digitalWrite(5,LOW);
    delay(t);
}

void loop() {
  int adcData = analogRead(0);
  Serial.println(adcData);
  if(adcData>200)
  {
    Blink(100);
  }
  else
    Blink();
}
