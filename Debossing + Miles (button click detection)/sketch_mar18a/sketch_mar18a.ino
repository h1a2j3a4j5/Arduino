
#define ledR D2
#define btnR D4
unsigned long lastBtnPressTime;
int lastBtnVal;
bool redIsOn = true;

void setup() {
pinMode(ledR , OUTPUT);  
pinMode(btnR , INPUT_PULLUP);
digitalWrite(ledR ,LOW);
lastBtnPressTime = millis();
Serial.begin(9600);
}



void loop() {
int btnVal =  digitalRead(btnR);
Serial.println("הזמן האחרון");
Serial.println(lastBtnPressTime);
if(btnVal == LOW && lastBtnVal == HIGH &&  millis() -  lastBtnPressTime >= 100){
    Serial.println("הזמן החדש");
    Serial.println(millis());
    lastBtnPressTime = millis();
    toggle();
}
  lastBtnVal = btnVal;
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
  digitalWrite(ledR ,HIGH);
  redIsOn = true;
}


void redOff (){
  digitalWrite(ledR ,LOW);
  redIsOn = false;
}
