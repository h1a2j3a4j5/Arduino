#define BtnR     D1
#define ledRed   D4
#define ledGreen D3 

unsigned long lastBtnPressTimeRed;
unsigned long lastBtnPressTimeGreen;
unsigned long lastBtnPressTimeBtn;
int lastBtnValRed ,lastBtnValGreen , lastBtnVal; 
bool isRed = true;
bool isGreen = true;
bool isOff = true;


void setup() {
pinMode(BtnR, INPUT_PULLUP);
pinMode(ledRed , OUTPUT);
pinMode(ledGreen , OUTPUT);
Serial.begin(9600);

wifi_Setup();
lastBtnPressTimeRed = millis();
lastBtnPressTimeGreen = millis();
lastBtnPressTimeBtn = millis();


if(GetData() == 25){
    redOn ();
    isRed = false;
    isGreen = false;
}

if(GetDataG() == 35){
     greenOn ();
}


}

void loop() {
int btnVal = digitalRead(BtnR); 
if(btnVal == LOW && lastBtnValRed == HIGH && millis() - lastBtnPressTimeRed > 50 && isRed == true){
  lastBtnPressTimeRed = millis();
   SendData(25);
   GetData();
   redOn ();
   isRed = false;
 }
 lastBtnValRed = btnVal;

if(btnVal == LOW && lastBtnValGreen == HIGH && millis() - lastBtnPressTimeGreen > 50 && isGreen == false){
  lastBtnPressTimeGreen = millis();
   SendDataG(35);
   GetDataG();
   greenOn();

 }
 lastBtnValGreen = btnVal ;





//if(btnVal == LOW && lastBtnVal == HIGH && millis() - lastBtnPressTimeBtn > 50 ){
//  lastBtnPressTimeBtn = millis();
//  SendDataG(55);
//  GetDataG();
//  TurnOffLights(); 
//}
//lastBtnVal = btnVal; 

}

void redOn (){
  digitalWrite(ledRed , HIGH);
}

void greenOn () {
   digitalWrite(ledGreen , HIGH);
}

void TurnOffLights () {
   digitalWrite(ledGreen , LOW);
   digitalWrite(ledRed , LOW);
}
