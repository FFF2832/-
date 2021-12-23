#include "pitches.h"
#include <BluetoothSerial.h>
BluetoothSerial BT;
//4pins超音波測距模組
int triggerPin = 17; //用來trigger
int echoPin = 16; //用來接收echo
long duration, cm, inches;
int length;
byte num=1;
int flag=1; 
 int melody[] = {  
    NOTE_B5 , NOTE_G5,NOTE_D5, NOTE_G5, NOTE_A5, NOTE_D6, NOTE_A5,
  NOTE_B5, NOTE_A5, NOTE_D5, NOTE_G5
  };
int freq = 2000;
int channel = 0;
int resolution = 8;
  int noteDurations[] = {  
1,1,1,1,1,3,1,1,1,1,3
  };
void setup() {
  Serial.begin (115200);  // Serial Port begin
  BT.begin("candyTestEsp32");
  pinMode(triggerPin, OUTPUT); //發送超音波
  pinMode(echoPin, INPUT);  //讀取超音波
   length = sizeof(melody)/sizeof(melody[0]);
  ledcSetup(0, 2000, 8);
  ledcAttachPin(18, 0);
}
 
void loop()
{
  
  //發送超音波
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(5);
  digitalWrite(triggerPin, HIGH);  // 給 Trig 高電位，持續 10微秒
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  //接收超音波
  duration = pulseIn(echoPin, HIGH);   // 收到高電位時的時間

  //將回傳時間換算成距離 cm 或 inch 
  cm = (duration/2) / 29.1;          
  
  Serial.print("Distance : ");  
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  if(cm<=8){BT.write(num);}   
  if(cm<=8&&flag){
    flag=0;
    for (int thisNote = 0; thisNote < length; thisNote++) {
      int noteDuration = noteDurations[thisNote]*230;
      ledcWriteTone(channel, melody[thisNote]);
      delay(noteDuration);
      ledcWriteTone(channel, 0);
      int pauseBetweenNotes = noteDuration;
      delay(pauseBetweenNotes);} 
    }
  if(cm>8){flag=1;}
  delay(250);
}
