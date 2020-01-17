#include<EEPROM.h>
int count = 1;
int redpin = 6;
int greenpin = 5;
int bluepin = 3;

byte fndData[10][7] = {
  {0,0,0,0,0,0,1},
  {1,0,0,1,1,1,1},
  {0,0,1,0,0,1,0},
  {0,0,0,0,1,1,0},
  {1,0,0,1,1,0,0},
  {0,1,0,0,1,0,0},
  {0,1,0,0,0,0,0},
  {0,0,0,1,1,1,1},
  {0,0,0,0,0,0,0},
  {0,0,0,0,1,0,0}
};

 unsigned char color[5][3] = {
      {255,255,0},
      {255,150,0},
      {150,255,0},
      {30,255,150},
      {0,255,255}
    };

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  count = EEPROM.read(0);//eeprom
  if(count > 5){
      count = 1;
    }
    //pinMode(4,OUTPUT);//?????
  for(int i=7;i<=13;i++)
  {
    pinMode(i,OUTPUT);
  }//fnd
  pinMode(2,INPUT_PULLUP);//switch
  attachInterrupt(0,interrupt,RISING);//interrupt
  pinMode(redpin,OUTPUT);//r
  pinMode(greenpin,OUTPUT);//g
  pinMode(bluepin,OUTPUT);//b
}

void loop() {
  // put your main code here, to run repeatedly:
  int temp = Serial.read();
  int temp2 = Serial.read();
  delay(10);

  if(temp < 57 && temp > 47)
  {
    count = checkSerial(temp,temp2);
  }
  displayNum(count);
  setRgbColor(color[count-1][0],color[count-1][1],color[count-1][2]);
  EEPROM.write(0,count);
}

void interrupt()
{
  count++;
  if(count > 5){
      count = 1;
    }
}

int checkSerial(int n, int n2)
{
  if(n>=48 && n2 ==10)
    return 1;
  else if(n==49 && n2 ==48)
    return 1;
  else if(n == 49 && n2 <= 57 && n2 > 48 )
    return 2;
  else if(n==50 && n2 ==48)
    return 2;
  else if(n == 50 && n2 <= 57 && n2 > 48 )
    return 3;
  else if(n==51 && n2 ==48)
    return 3;
  else if(n == 51 && n2 <= 57 && n2 > 48 )
    return 4;
  else if(n==52 && n2 ==48)
    return 4;
  else if(n == 52 && n2 <= 57 && n2 > 48 )
    return 5;
  else if(n==53 && n2 ==48)
    return 5;
}
void displayNum(byte num)
{
  for(int i=7;i<=13;i++)
  {
    digitalWrite(i,fndData[num][i-7]);
  }
}
void setRgbColor(char r, char g, char b)
{
  analogWrite(redpin,255-r);
  analogWrite(greenpin,255-g);
  analogWrite(bluepin,255-b); 
}
