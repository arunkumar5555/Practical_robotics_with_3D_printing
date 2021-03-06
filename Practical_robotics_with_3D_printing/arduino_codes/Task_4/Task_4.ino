// controlling car through Bluetooth classic 

#include "BluetoothSerial.h"
// Defing the pins 

#define motorRa 27
#define motorRb 14
#define motorLa 25
#define motorLb 26
#define Rpwm 12
#define Lpwm 33
const int channel_R = 0;
const int channel_L = 1;
const int freq = 5000;
const int res =8;
char command;
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  setup_motors();
  SerialBT.begin("Car Availble to drive ");
}

void loop() {

  if (SerialBT.available()) {
      command=SerialBT.read();
    
  }

  switch (command) {
    case 'f':
      forward();
      break;
    case 'b':
      reverse();
      break;
    case 'r':
      right();
      break;
    case 'l':
      left();
      break;
    case 's':
      stopp();
      break;
}
  
  }

void stopp(){
  ledcWrite(channel_R , 0);                             
  ledcWrite(channel_L , 0);
}

void reverse(){
  digitalWrite(motorLa,LOW);
  digitalWrite(motorRa,LOW);
  digitalWrite(motorLb,HIGH);
  digitalWrite(motorRb,HIGH);
  ledcWrite(channel_R , 150);                             
  ledcWrite(channel_L , 150);
}
void forward(){
  digitalWrite(motorLa,HIGH);
  digitalWrite(motorRa,HIGH);
  digitalWrite(motorLb,LOW);
  digitalWrite(motorRb,LOW);
  ledcWrite(channel_R , 150);                             
  ledcWrite(channel_L , 150);
}

void left(){
  digitalWrite(motorLa,LOW);
  digitalWrite(motorRa,HIGH);
  digitalWrite(motorLb,LOW);
  digitalWrite(motorRb,LOW);
  ledcWrite(channel_R , 150);                             
  ledcWrite(channel_L , 150);
}
void right(){
  digitalWrite(motorLa,HIGH);
  digitalWrite(motorRa,LOW);
  digitalWrite(motorLb,LOW);
  digitalWrite(motorRb,LOW);
  ledcWrite(channel_R , 150);                             
  ledcWrite(channel_L , 150);
}

void setup_motors(){

  pinMode(motorLa, OUTPUT);
  pinMode(motorLb, OUTPUT);
  pinMode(motorRa, OUTPUT);
  pinMode(motorRb, OUTPUT);
  ledcSetup(channel_R ,freq , res);
  ledcSetup(channel_L ,freq , res);
  ledcAttachPin(Rpwm,channel_R);
  ledcAttachPin(Lpwm,channel_L);
  ledcWrite(channel_R , 150);                             
  ledcWrite(channel_L , 150);
}
