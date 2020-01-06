boolean ledStatus=LOW;
int count = 0;
int swBuf =0 ;
int fndCount = 0;

byte fndData[9][7] = {
  {0,0,0,0,0,0,0},
  {1,1,1,0,0,0,0},
  {0,1,0,0,0,0,0},
  {0,0,1,0,0,0,0},
  {0,0,0,1,0,0,0},
  {0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0},
  {0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1}
};
void setup() {
  // put your setup code here, to run once:
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
pinMode(13, INPUT_PULLUP);
for(int i = 0; i <9; i++)
{
  pinMode(i, OUTPUT);
}
attachInterrupt(0,interrupt,RISING);
}
void displayNum(byte num)
{
  for(int i = 0; i<9;i++)
  {
    digitalWrite(i, fndData[num][i-1]);
  }
}
void interrupt()
{
  ledStatus=!ledStatus;
  }
unsigned char color[5][3] = {
   {0,0,255}
  ,{0,143,255}
  ,{143,0,255}
  ,{207,0,47}
  ,{255,0,0}
};
void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(13) == LOW && swBuf == 0)
{
  swBuf = 1;
}
else if(digitalRead(13) == HIGH && swBuf == 1)
{
  swBuf = 0;
  count++;
  if(count > 4)
  {
    count = 0;
  }
}
displayNum(fndCount++);

   if(fndCount > 8)
 {
  fndCount = 0;
 }
 delay(1000);
  
setRgbColor(color[count][0],color[count][1],color[count][2]);
}
void setRgbColor(char r, char g, char b)
{
  analogWrite(11, 255 - r);
  analogWrite(10, 255 - g);
  analogWrite(9, 255 - b);
};
