#include <EEPROM.h>
int count=0;
int swBuf=0;
int seNum1=0;
int seNum2=0;

byte fndData[5][7] = {
  {1,0,0,1,1,1,1},
  {0,0,1,0,0,1,0},
  {0,0,0,0,1,1,0},
  {1,0,0,1,1,0,0},
  {0,1,0,0,1,0,0},
};
unsigned char color[5][3]=
{/*
      {0,0,255},
      {0,143,255},
      {143,0,255},
      {207,0,47},
      {255,0,0}
  */
   {255,255,0},
      {255,150,0},
      {150,255,0},
      {30,255,150},
      {0,255,255}
  };
void setup() {
   Serial.begin(9600);
   pinMode(6,OUTPUT);//r
  pinMode(5,OUTPUT);//g
  pinMode(3,OUTPUT); //b
    for(int i=7;i<=13;i++)
  {
    pinMode(i,OUTPUT);
  }//fnd
  pinMode(2,INPUT_PULLUP);//switch
  attachInterrupt(0,interrupt,RISING);
 
  count = EEPROM.read(0);
  if(count >= 5){
      count = 0;
    }
}
void interrupt()
{
  count++;
  if(count >= 5){
      count = 0;
    }
}
void loop() {
  // put your main code here, to run repeatedly:

    seNum1=Serial.read();
    seNum2=Serial.read();
    if(seNum1 < 57 && seNum1> 47)
  {
    if(seNum1>=48&&seNum2==10)
    {
       count=0;
      }
    else if(seNum1==49&&seNum2==48)
    {
       count=0;
      }
    else if(seNum1 == 49 && seNum2 <= 57 && seNum2 > 48)
    {
       count=1;
      }
      else if(seNum1==50 && seNum2 ==48)
    {
       count=1;
      }
      else if(seNum1 == 50 && seNum2 <= 57 && seNum2 > 48)
    {
       count=2;
      }
      else if(seNum1==51 && seNum2 ==48)
    {
       count=2;
      }
     else if(seNum1 == 51 && seNum2 <= 57 && seNum2 > 48)
    {
       count=3;
      }
      else if(seNum1==52 && seNum2 ==48)
    {
       count=3;
      }
      else if(seNum1 == 52 && seNum2 <= 57 && seNum2 > 48 )
    {
       count=4;
      }
      else if(seNum1==53 && seNum2 ==48)
    {
       count=4;
      }
  }
        displayNum(count);
        setRgbColor(color[count][0],color[count][1],color[count][2]);
        EEPROM.write(0,count);
 }
 void displayNum(byte num)
{    
  for(int i =7;i<=13;i++)
  {
    digitalWrite(i,fndData[num][i-7]);
  }
}
void setRgbColor(char r,char g,char b)
{
  analogWrite(6,255-r);
  analogWrite(5,255-g);
  analogWrite(3,255-b);
 } //시리얼넘버 0~10
