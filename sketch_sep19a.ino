int count = 0;
boolean stopflag = false;
byte fnddata[10][7] = {
  {1,0,0,1,1,1,1},
  {0,0,1,0,0,1,0},
  {0,0,0,0,1,1,0},
  {1,0,0,1,1,0,0},
  {0,1,0,0,1,0,0},
  {0,1,0,0,0,0,0},
};

void displaynum(byte num) {
 for (int i=5; i<13; i++)
  {
    digitalWrite(i, fnddata[num][i-6]);
  }
}
void setup() {
 for (int i=5; i<13; i++) {
      pinMode(i,OUTPUT);
 }
 pinMode(4,OUTPUT);
}

void loop() {
  int val = digitalRead(13);
  if(val ==LOW)
  stopflag = !stopflag;

  if(stopflag == false)
  {
    displaynum(count++);
    if (count >= 5)
    digitalWrite(4, HIGH);
   else
   digitalWrite(4, LOW);
    if(count>6)
    count=0;
  }
delay(50);
}
