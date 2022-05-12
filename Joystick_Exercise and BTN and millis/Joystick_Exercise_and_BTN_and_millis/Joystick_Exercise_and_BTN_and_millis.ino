
#define ledRed      D6
#define ledGreen    D5
#define Vrx         A0
#define btn_G       D7 

void setup() {
  pinMode(ledRed , OUTPUT);
  pinMode(ledGreen ,OUTPUT);
  pinMode(btn_G ,INPUT_PULLUP);

  Serial.begin(9600);
}
bool check ;
unsigned long checkTime;
bool isLedOn;
void loop(){ 
   int x =  analogRead(Vrx);
   delay(100);
   if(check){
    if(millis() - checkTime > 500) {
    togleled ();
     checkTime = millis();
   }
 }

   if(x < 300 ){
     check = false;
   }
   if(x > 500 ){
    check = true;
   }
   
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
