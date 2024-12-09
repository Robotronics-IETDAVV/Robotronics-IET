////ROBOTRONICS
///Created by Ambika Joshi
/*
This project simulates the rolling of a dice 
using an electronic 7-segment display. 
The circuit allows users to "roll" the dice 
by pressing a button and display the resulting number (1 to 6) 
on a 7-segment display. 
A second button resets the display to show 
a default state (e.g., a dash or blank). 
The dice "rolling" effect is achieved by cycling 
through possible dice numbers before settling on a random value.
*/

#define resett 9 ///for resetting the dice number
#define dice 8    ////for getting dice number

char digit[6]={0x02, 0x79, 0x24, 0x30, 0x19, 0x12};
int pin[7]={6,5,4,3,2,1,0};

void setup() {

  for(int i=0;i<7;i++)
  pinMode(pin[i], OUTPUT);
  pinMode(dice, INPUT);
  pinMode(resett, INPUT);
  digitalWrite(dice, HIGH);
  digitalWrite(resett, HIGH);

   int temp=0x40;
    for(int i=0;i<7;i++) {
      int temp1=temp&0x01;
      digitalWrite(pin[i], temp1);
      temp=temp>>1;
    }
    delay(1000);
}

void loop() {
  int temp=rand();
  if(digitalRead(dice)==0) {
    int k=temp%6;
    temp=digit[k];
    wait();
    for(int i=0;i<7;i++) {
      int temp1=temp&0x01;
      digitalWrite(pin[i], temp1);
      temp=temp>>1;
    }
    delay(200);
  }

  if(digitalRead(resett)==0) {
    temp=0x40;
    for(int i=0;i<7;i++) {
      int temp1=temp&0x01;
      digitalWrite(pin[i], temp1);
      temp=temp>>1;
    }
  }
}

void wait() {
  for(int m=0;m<10;m++) {
   for(int k=0;k<6;k++) {
    int ch=digit[k];
    for(int l=0;l<7;l++) {
      char tem2=ch&0x01;
      digitalWrite(pin[l], tem2);
      ch=ch>>1;
    }
    delay(50);
   }
  } 
}
