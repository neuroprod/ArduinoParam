

#include <ArduinoParam.h>
#include <LiquidCrystal.h>


int encoderPin1 = 3;
int encoderPin2 = 2;
int encoderSwitchPin = 4; //push button switch
int nextSwitchPin = 5; //push button switch
int prevSwitchPin = 6; //push button switch
double prevTime;
boolean btnPressed;

ArduinoParam param;

float a=2.45;
void setup() {
  Serial.begin (9600);
  prevTime =0;
  pinMode(encoderPin1, INPUT_PULLUP); 
  pinMode(encoderPin2, INPUT_PULLUP);
  pinMode(encoderSwitchPin, INPUT_PULLUP);
  pinMode(nextSwitchPin, INPUT_PULLUP);
  pinMode(prevSwitchPin, INPUT_PULLUP);

  attachInterrupt(encoderPin2, updateEncoder, FALLING ); 
  attachInterrupt(encoderSwitchPin, goEncoderBtn, FALLING); 
  attachInterrupt(nextSwitchPin, goNext, RISING ); 
  attachInterrupt(prevSwitchPin, goPrevious, RISING ); 


  Node *n=param.addMenu("test");
  Node *n2 =param.addMenu("test2");
  n2->addFloat("a",a,1,0,100);
  n->addMenu("sub0");
  n->addMenu("sub1");
  n->addMenu("sub2");
  param.start();
}

void loop(){ 
 if(btnPressed){
   Serial.println("btnRot");
    btnPressed=false;
 }
}

void goEncoderBtn(){
  btnPressed=true;
}
void goPrevious(){
  double time =millis();
  if(time-prevTime>200)
  param.back();
  prevTime = time;
}
void goNext(){
  double time =millis();
   if(time-prevTime>200)
  param.select();
 prevTime = time;
}
void updateEncoder(){

  
  int b = digitalRead(encoderPin1); 
  if(b==0)param.goUp();
  if(b==1)param.goDown();
  
  
 
}
