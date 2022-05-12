#include <ASCIIDic.h>

#include <NX7Seg.h>

#define  IN       D4
#define   C       D7
#define   B       D6
#define   A       D5
#define inUot     A0
#define btn       D1
#define led       D2


#define CLK_DIO   D5   

#define LATCH_DIO D6 

#define DATA_DIO  D7  

#define Amount  6

nx7seg my4x7seg = nx7seg(LATCH_DIO, CLK_DIO, DATA_DIO , true); 





int correctCode [Amount];
int check [Amount] = {5,5,5,3,3,3}; 
unsigned long lastTime;
bool redIsOn = true;
bool one = true;
int lastBtnVal;
int PressedBtn = 0;
int realCode = 5;
void setup() {
   pinMode(IN , OUTPUT);
   pinMode(A , OUTPUT);
   pinMode(B , OUTPUT);
   pinMode(C , OUTPUT);
   pinMode(LATCH_DIO, OUTPUT);
   pinMode(CLK_DIO, OUTPUT);
   pinMode(DATA_DIO, OUTPUT);
   pinMode(inUot , INPUT);
   pinMode(btn , INPUT_PULLUP);
   pinMode(led , OUTPUT);
   Serial.begin(9600);
   digitalWrite(led , HIGH);
   wifi_setup ();
}

void loop() {
  Serial.println(PressedBtn);
  showSensorsValues();
if(isBtnPreesed () ) {
  correctCode[PressedBtn] = ReadMuxChannel();
   PressedBtn++;
}
  

if(PressedBtn >= Amount){
  for(int k = 0; k < Amount;k++){
   if(correctCode[k] != check[k]){
       one = false;
      }
    }
    if(one == false ){
    Serial.println("NOT");
    PressedBtn = 0;
   }
    else{
    Serial.println("YES");
    PressedBtn = 0;
    openSave();
    toggle ();
  }
}

 wifi_loop();

}






void activeRealy () {
  digitalWrite(IN , LOW);
}

void activeNotRealy () {
   digitalWrite(IN , HIGH);
}


int ReadMuxChannel() {
    digitalWrite(C  ,LOW);
    digitalWrite(B  ,HIGH);
    digitalWrite(A  ,HIGH);    
    int ret =  map( analogRead(inUot) , 0 , 1023 , 1 , 8);
    
    return ret;
}

int ReadLdr() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  int ret = map(analogRead(inUot), 0, 1023, 1, 8);
  return ret;
}


void openSave() {
  activeRealy ();
  unsigned long lastTime = millis();
  while(millis() - lastTime < 5000 && ReadLdr() < 3 );
  activeNotRealy ();
}

void showSensorsValues() {
  my4x7seg.writeDigit(ReadMuxChannel(), 0);
  my4x7seg.refresh(200);
}

int isBtnPreesed () {
  bool preesed = false;
  int btnVal = digitalRead(btn);
  if(btnVal  == LOW  && lastBtnVal == HIGH && millis() - lastTime >= 100 && preesed == false){
   preesed = true;
  lastTime = millis();

}
  lastBtnVal = btnVal;

  return preesed;
}


void toggle (){
  if(redIsOn){
    redOff ();
   }
 else{
  redOn ();
  }
} 


void redOn (){
  digitalWrite(led ,HIGH);
  redIsOn = true;
}


void redOff (){
  digitalWrite(led ,LOW);
  redIsOn = false;
}
