
#include <Servo.h>

#define PinServo   D7
#define inUot      A0
#define LdrIsLdrConnectedPin  D1

Servo myservo;
bool IsLdrConnected;

void setup() {
  myservo.attach(PinServo);
  pinMode(LdrIsLdrConnectedPin ,INPUT_PULLUP);
  Serial.begin(9600);
  
  wifi_Setup();
  
  IsLdrConnected = (digitalRead(LdrIsLdrConnectedPin) == LOW)? true: false; 

  
  Serial.println(IsLdrConnected);

}

void loop() {
if(IsLdrConnected) {
  int AnalogLdr = map(analogRead(inUot) , 0 , 1023 , 0 , 90);
   SendData(AnalogLdr);
 }
 else {
  myservo.write(GetData());
  delay(3000);
  myservo.write(0);
  delay(3000);
}
analogWrite(led ,GetData());
 
}





//int check () {
//  int ret = 0;
//  ret =  map(analogRead(inUot) , 0 , 1023 , 0 , 90);
//    
//  return ret;
//}
//
//void ch () {
//  
//   SendData(check ());
//   myservo.write(GetData());
//   delay(3000);
//   myservo.write(0);
//   delay(3000);
//}
