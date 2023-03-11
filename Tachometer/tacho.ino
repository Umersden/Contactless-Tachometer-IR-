#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,7,6,5,4);
#define sensor 3
#define start 12
int delay1()
{
//unsigned int long k;
int i,j;
unsigned int count=0;
for(i=0;i<10;i++)
{
for(j=0;j<1000;j++)
{
if(digitalRead(sensor)==HIGH)
{
count++;
while(digitalRead(sensor)==HIGH);
}
}
}
return count;
}
void setup()
{
  Serial.begin(9600);
pinMode(sensor, INPUT);
pinMode(start, INPUT);
pinMode(2, OUTPUT);
lcd.begin(16, 2);
lcd.print(" Tachometer");
delay(2000);
digitalWrite(start, HIGH);
}
void loop()
{
unsigned int time=0,RPM=0;
lcd.clear();
lcd.print(" Please Press ");
lcd.setCursor(0,1);
lcd.print("Button to Start ");

lcd.clear();
lcd.print("Reading RPM..");
time=delay1();
lcd.clear();
lcd.print("Please Wait..");
RPM=(time*12);
delay(2000);
lcd.clear();
lcd.print("RPM=");Serial.println(RPM);
lcd.print(RPM);
delay(5000);
}
