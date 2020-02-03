int count = 0;
boolean stopFlag = false;
byte fndData[10][7] = {
  {1,0,0,1,1,1,1},
  {0,0,1,0,0,1,0},
  {0,0,0,0,1,1,0},
  {1,0,0,1,1,0,0},
  {0,1,0,0,1,0,0},
  {0,1,0,0,0,0,0},
};

void displayNum(byte num)
{
  for(int i =6;i<13;i++)
  {
    digitalWrite(i,fndData[num][i-6]);
  }
}

void setup() {
  for(int i=5;i<13;i++)
  {
    pinMode(i,OUTPUT);
  }
  pinMode(13,INPUT_PULLUP);
}

void loop() {
 int val = digitalRead(13);
 if(val == LOW)
 {
  stopFlag = !stopFlag;
 }
 if(stopFlag == false)
 {
  displayNum(count++);
  if(count>6){
    count = 0;
  }
 }
 delay(50);
}
