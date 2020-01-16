int count = 0;
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

void displayNum(byte num)
{
  for(int i =06;i<13;i++)
  {
    digitalWrite(i,fndData[num][i-6]);
  }
}

void setup() {
  for(int i=5;i<13;i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop() {
  displayNum(count++);
  if(count>9)
  {
    count = 0;
  }
  delay(500);
}
