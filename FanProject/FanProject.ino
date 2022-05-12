

#define A1A  D8
#define AB1  D7


#define BtnFwd  D3
#define BtnBack D4

unsigned long lastTime;
unsigned long lastTimeTwo;
int LastBtnVal;
int LastBtnValTwo;
int FanState = 0;
int FanState2 = 0;

void setup() {
 pinMode(BtnFwd , INPUT_PULLUP); 
 pinMode(BtnBack , INPUT_PULLUP);
 pinMode(A1A , OUTPUT);
 pinMode(AB1 , OUTPUT);
 Serial.begin(9600);
wifi_Setup();
SendData(2);
GetData();
}

void loop() {
    if(GetData() == 2){
       Rotate_Fwd();
    }
    else if(GetData() == 3){
       Rotate_Back();
    }
    else{
      Rotate_OFF();
 }
  if(FwdButton ()) {
     FanState = (FanState + 1) % 2;
     FanControl();
  }

  if(BackButton () ){
      FanState2 = (FanState2 + 1) % 2;
      FanContro2();
  }



 }



bool FwdButton () {
  bool PressLeft = false;
  int BtnVal = digitalRead(BtnFwd);
  

  if(BtnVal == LOW && LastBtnVal == HIGH && millis() - lastTime > 50){
     lastTime = millis();  
     PressLeft = true;
    
 }
  LastBtnVal = BtnVal;
  return PressLeft;
}



bool BackButton () {
  bool PreesRight = false;
  int BtnValTwo = digitalRead(BtnBack);
  
   if(BtnValTwo == LOW &&  LastBtnValTwo == HIGH && millis() -  lastTimeTwo > 100 ){
      lastTimeTwo = millis ();
      PreesRight = true;

   }
   LastBtnValTwo = BtnValTwo;
   return PreesRight;
}


void FanControl() {
  switch (FanState) {
    case 0: Rotate_OFF(); break;
    case 1: Rotate_Back(); break;   
  }
}

void FanContro2() {
  switch (FanState2) { 
    case 0: Rotate_OFF(); break;
    case 1: Rotate_Fwd(); break;  
  }
}


void Rotate_OFF() {
  digitalWrite(A1A, HIGH);
  digitalWrite(AB1, HIGH);
}
void Rotate_Fwd() {
  digitalWrite(A1A, HIGH);
  digitalWrite(AB1, LOW);
}
void Rotate_Back() {
  digitalWrite(A1A, LOW);
  digitalWrite(AB1, HIGH);
}
