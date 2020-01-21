int swcount = 0;
int swbuf = 0;
int adcpin1 = A0;
int adcpin2 = A1;

void setup() {
  // put your setup code here, to run once:
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int adcData1 = analogRead(adcpin1);
  int adcData2 = analogRead(adcpin2);
int val1 = adcData1/4;
int val2 = adcData2/4;
Serial.println(val1, DEC);  
Serial.println(val2, DEC);  
setRgbColor(0,val1,val2);
}

void setRgbColor(char r, char g, char b)
{
  analogWrite(11,255-r);
  analogWrite(10,255-g);
  analogWrite(9,255-b);
}
