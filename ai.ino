
#include <BluetoothSerial.h>
BluetoothSerial BT;
int freq = 2000;
int channel = 0;
int resolution = 8;

byte num=1;


void setup() {
 
Serial.begin(115200);
  BT.begin("candyTestEsp32");
  pinMode(12,INPUT);
  pinMode(13,INPUT);
   pinMode(14,INPUT);

  ledcSetup(0, 2000, 8);
  ledcAttachPin(18, 0);
  
}

void loop() {
  int doll = digitalRead(12);
  int coffee = digitalRead(13);
   int phone = digitalRead(14);
  
//  Serial.print("doll:");
//  Serial.print(doll);
//  Serial.print(" coffee:");
//  Serial.println(coffee);
//  Serial.print(" phone:");
//  Serial.println(phone);
  if(doll == 1){
    ledcWriteTone(0, 1000);
    delay(50);
    ledcWriteTone(0, 2000);
    delay(50);
//    ledcWriteTone(0, 1000);
//    delay(100);
//    ledcWriteTone(0, 2000);
//    delay(100);

    Serial.println("doll");
    
    delay(500);
  }
  else if(coffee == 1){
    ledcWriteTone(0, 1000);
    delay(100);
    ledcWriteTone(0, 2000);
    delay(100);
//    ledcWriteTone(0, 1000);
//    delay(100);
//    ledcWriteTone(0, 2000);
//    delay(100);
    Serial.println("coffee");
    delay(500);
  }
  else if(phone == 1){
    ledcWriteTone(0, 1000);
    delay(100);
    ledcWriteTone(0, 2000);
    delay(100);
//    ledcWriteTone(0, 1000);
//    delay(100);
//    ledcWriteTone(0, 2000);
//    delay(100);
    Serial.println("phone");
    delay(500);
  }
  else{
    ledcWriteTone(0, 0);
    
  }
  
}
