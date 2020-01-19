#include <EEPROM.h>
int count = 0;
int incomingByte;
int isString1 = 0;
String isString = "";
boolean switchState = false;
byte fndData[5][7] = {
  {1,0,0,1,1,1,1},
  {0,0,1,0,0,1,0},
  {0,0,0,0,1,1,0},
  {1,0,0,1,1,0,0},
  {0,1,0,0,1,0,0},
};

unsigned char color[5][3] = {
   {0,0,255}
  ,{0,153,255}
  ,{153,0,255}
  ,{204,0,51}
  ,{255,0,0}
};


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(2, INPUT_PULLUP);
attachInterrupt(0, interrupt1, RISING);
isString1 = EEPROM.read(0);
  for(int i = 7; i <14; i++)
  {
   pinMode(i, OUTPUT);
  }
}

void interrupt1()
{
    isString1 += 10;
    if(isString1 > 50)
    {
     isString1 = isString1%50;
    }
}


void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
{
  incomingByte = Serial.read();
  if(isDigit(incomingByte))
  {
    isString += (char)incomingByte; 
  }
  if(incomingByte == '\n')
  {
    Serial.println(isString.toInt());
    isString1 = isString.toInt();
    isString = "";
  }
} 
if(isString1 >= 0 )
 {
  count = 0;
 }
 if(isString1 > 10)
 {
   count = 1;
 }
  if(isString1 > 20)
 {
  count = 2;
 }
  if(isString1 > 30)
 {
  count = 3;
 }
 if(isString1 > 40)
 {
  count = 4;
 }
displayNum(count);
setRgbColor(color[count][0],color[count][1],color[count][2]); 
EEPROM.write(0,isString1);
}

void displayNum(int num)
{  
 for(int i = 7; i < 14;i++)
  {
    digitalWrite(i, fndData[num][i-7]);
  }
}
void setRgbColor(char r, char g, char b)
{
  analogWrite(6, 255 - r);
  analogWrite(5, 255 - g);
  analogWrite(3, 255 - b);
};
