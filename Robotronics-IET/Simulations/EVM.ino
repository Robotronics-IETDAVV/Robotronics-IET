///ROBOTRONICS CLUB
////EVM
////Created by Neha Tekam
/*It is a system that allows users to cast their votes 
using buttons, displays the results on an LCD, 
and provides feedback using LEDs. 
This project is a simple and efficient way to demonstrate 
basic voting machine principles using Arduino*/

#include<LiquidCrystal.h>
LiquidCrystal lcd(11,10,9,8,7,6);
#define sw1 A0 // Button 1
#define sw2 A1 // Button 2
#define sw3 A2 // Button 3
#define sw4 A3 // Button 4
#define sw5 A4 // Button 5 for result
int vote1=0;
int vote2=0;
int vote3=0;
int vote4=0;
void setup(){
pinMode(sw1, INPUT);
pinMode(sw2,INPUT);
pinMode(sw3,INPUT);
pinMode(sw4,INPUT);
pinMode(sw5,INPUT);
pinMode(13,OUTPUT);// Red LED
pinMode(12,OUTPUT);// Green LED

lcd.begin(16, 2);
lcd.setCursor(0,0);
lcd.print("VOTING MACHINE ");
lcd.setCursor(0,1);
lcd.print("Circuit desigh ");
delay(1000);
digitalWrite(sw1, HIGH);
digitalWrite(sw2, HIGH);
digitalWrite(sw3, HIGH);
digitalWrite(sw4, HIGH);
digitalWrite(sw5, HIGH);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("1");
lcd.setCursor(4,0);
lcd.print("2");
lcd.setCursor(8,0);
lcd.print("3");
lcd.setCursor(12,0);
lcd.print("4");
}
void loop()
{
lcd.setCursor(0,0);
lcd.print("1");
lcd.setCursor(1,1);
lcd.print(vote1);
lcd.setCursor(4,0);
lcd.print("2");
lcd.setCursor(5,1);
lcd.print(vote2);
lcd.setCursor(8,0);
lcd.print("3");
lcd.setCursor(9,1);
lcd.print(vote3);
lcd.setCursor(12,0);
lcd.print("4");
lcd.setCursor(13,1);
lcd.print(vote4);

if(digitalRead(sw1)==0)
{ 
vote1++;
  digitalWrite(12,HIGH);
 delay(500);
while(digitalRead(sw1)==0);
digitalWrite(12,LOW);
delay(1000);

}

if(digitalRead(sw2)==0)
{

vote2++;
  digitalWrite(12,HIGH);
  delay(500);
while(digitalRead(sw2)==0);
digitalWrite(12,LOW);
delay(1000);

}

if(digitalRead(sw3)==0)
{

vote3++;
  digitalWrite(12,HIGH);
  delay(500);
while(digitalRead(sw3)==0);
digitalWrite(12,LOW);
delay(1000);
}

if(digitalRead(sw4)==0)
{

vote4++;
  digitalWrite(12,HIGH);
  delay(500);
while(digitalRead(sw4)==0);
digitalWrite(12,LOW);
delay(1000 );
}

if(digitalRead(sw5)==0)
{
digitalWrite(13,HIGH);
int vote=vote1+vote2+vote3+vote4;
if(vote)
{
if((vote1 > vote2 && vote1 > vote3 && vote1 > vote4))
{
lcd.clear();
lcd.print("1 Wins");
delay(5000);
lcd.clear();
}
else if((vote2 > vote1 && vote2 > vote3 && vote2 > vote4))
{
lcd.clear();
lcd.print("2 Wins");
delay(5000);
lcd.clear();
}
else if((vote3 > vote1 && vote3 > vote2 && vote3 > vote4))
{
lcd.clear();
lcd.print("3 Wins");
delay(5000);
lcd.clear();
}
else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
{
lcd.setCursor(0,0);
lcd.clear();
lcd.print("4 Wins");
delay(5000);
lcd.clear();
}

else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
{
lcd.setCursor(0,0);
lcd.clear();
lcd.print("5 Wins");
delay(2000);
lcd.clear();
}

else
{
lcd.clear();
lcd.print(" Tie Up Or ");
lcd.setCursor(0,1);
lcd.print(" No Result ");
delay(5000);
lcd.clear();
}

}
else
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("  No Voting….         ");
delay(5000);
lcd.clear();
}
vote1=0;vote2=0;vote3=0;vote4=0,vote=0;
lcd.clear();
digitalWrite(12,LOW);
digitalWrite(13,LOW);
}

}