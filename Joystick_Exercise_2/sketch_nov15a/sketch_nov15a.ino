#define ledRed      D1
#define Vrx         A0
#define ledGreen    D3
#define btn_R       D4
void setup() {
  pinMode(ledRed , OUTPUT);
  pinMode(ledGreen ,OUTPUT);
  pinMode(btn_R,INPUT_PULLUP);


  Serial.begin(9600);
}

bool check_R ;
bool check_G;
unsigned long checkTime;
unsigned long checkTimeGreen;
unsigned long checkTimeBtn;
bool isLedOn;
bool isLedOnG;

int lastBtnVal;

void loop(){ 
   int x =  analogRead(Vrx);
   
  
   
   if(check_R) {
   if(millis() - checkTime > 500) {
     togleled ();
     checkTime = millis();
   }
}

   if(check_G) {
   if(millis() - checkTimeGreen > 500) {
     toglledG ();
     checkTimeGreen = millis();
   }
}
   
   if(x > 600 ) {
    check_R = true;
    check_G = false;
   }
   if( x < 300 ) {
    check_R = false;
    check_G = true;
   }
    Serial.println(checkTimeBtn);
    Serial.println(millis());
    int btnVal = digitalRead(btn_R);
   if(btnVal == LOW  && lastBtnVal == HIGH && millis() - checkTimeBtn > 50 ){
    check_R = false;
    check_G = false;
    checkTimeBtn = millis();
   }
   lastBtnVal = btnVal;
}

void togleled () {
  if(isLedOn) {
    ledOff ();
  }else{
    LedOn ();
  }
}

void LedOn () {
  digitalWrite(ledRed,HIGH);
  isLedOn = true; 
}

void ledOff () {
  digitalWrite(ledRed,LOW);
  isLedOn = false; 
}







void toglledG () {
  if(isLedOnG) {
    ledOffG ();
  }else{
    LedOnG ();
  }
}

void LedOnG () {
  digitalWrite(ledGreen,HIGH);
  isLedOnG = true; 
}

void ledOffG () {
  digitalWrite(ledGreen,LOW);
  isLedOnG = false; 
}
