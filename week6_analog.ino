int ledpin = 11;
int adcpin = A0;

void setup() {
  // put your setup code here, to run once:
pinMode (ledpin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int adcData = analogRead(adcpin);
int val = adcData/4;
Serial.println(val,DEC);
analogWrite(ledpin,val);
}
