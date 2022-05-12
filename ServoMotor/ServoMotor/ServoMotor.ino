
#include <Servo.h>
#define vcc        3.3v
#define PinServo   D7
#define inUot      A0


Servo myservo;


void setup() {
   myservo.attach(PinServo);
  pinMode(inUot , OUTPUT);
  Serial.begin(9600);
  
  wifi_Setup();
  
  SendData(s()b);
}

void loop() {

 myservo.write(s();


}

int check () {
  int ret = 0;
  ret =  map(analogRead(inUot) , 0 , 1023 , 0 , 90);
    
  return ret;
}

int  s () {
  int num = check ();
  return num;
}
