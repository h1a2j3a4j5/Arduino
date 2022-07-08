#define ledRed D1
#define ledGreen D7
#define Vrx   A0
bool isLedOn;
unsigned long checkTime;
bool check = false;
void setup() {
  pinMode(ledRed , OUTPUT);
  pinMode(ledGreen ,OUTPUT);
  Serial.begin(9600);
}

void loop(){ 
      int x =  analogRead(Vrx); 
      if(x > 600 && millis() - checkTime > 5000){
          togleled ();
         
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
  checkTime = millis();
}

void ledOff () {
  digitalWrite(ledRed,LOW);
  isLedOn = false; 
  checkTime = millis();
}
