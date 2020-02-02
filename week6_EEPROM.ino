#include <EEPROM.h>
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
for (int i = 0 ; i<1024; i++)
{
EEPROM.write(i,i);
Serial.println("Write->"+String(i)+"\t value->"+String(i));
delay(50);
}

for (int i = 0 ; i<1024; i++)
{
int val = EEPROM.read(i,i);
Serial.println("read->"+String(i)+"\t value->"+String(i));
delay(50);
}
}
