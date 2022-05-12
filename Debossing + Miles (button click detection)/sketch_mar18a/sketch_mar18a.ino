
#define ledR D1
#define btnR D2
unsigned long lastBtnPressTime;
void setup() {
pinMode(ledR , OUTPUT);  
pinMode(btnR , INPUT_PULLUP);
digitalWrite(ledR ,LOW);
Serial.begin(9600);
}
bool check = false;

int lastBtnVal;
bool redIsOn = true;
void loop() {
int btnVal =  digitalRead(btnR);
Serial.println("הזמן האחרון");
Serial.println(lastBtnPressTime);
if(btnVal == LOW && lastBtnVal == HIGH && millis()- lastBtnPressTime >= 100){
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
