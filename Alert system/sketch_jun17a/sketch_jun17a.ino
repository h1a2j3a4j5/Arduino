#define BtnR     D1
#define ledRed   D4
#define ledGreen D3 
#define Room1    D2
#define Room2    D5
#define TurnOff  D6

unsigned long lastBtnPressTimeRed;
unsigned long lastBtnPressTimeGreen;
unsigned long lastBtnPressTimeBtn;

int lastBtnValRed ,lastBtnValGreen , lastBtnVal; 
bool IsRedConnected , IsGreenConnected ,IsBtnConnected;

void setup() {
pinMode(BtnR, INPUT_PULLUP);
pinMode(ledRed , OUTPUT);
pinMode(ledGreen , OUTPUT);
pinMode(Room1 , INPUT_PULLUP);
pinMode(Room2 , INPUT_PULLUP);
pinMode(TurnOff , INPUT_PULLUP);
Serial.begin(9600);

wifi_Setup();
lastBtnPressTimeRed = millis();
lastBtnPressTimeGreen = millis();
lastBtnPressTimeBtn = millis();

IsRedConnected = (digitalRead (Room1) == LOW) ? true: false;
IsGreenConnected = (digitalRead (Room2) == LOW) ? true: false;
IsBtnConnected = (digitalRead (TurnOff) == LOW) ? true: false;


}
void loop() {
int btnVal = digitalRead(BtnR); 
if(IsRedConnected && IsGreenConnected == false && IsBtnConnected == false){
   if(btnVal == LOW && lastBtnValRed == HIGH && millis() - lastBtnPressTimeRed > 50 ){
     lastBtnPressTimeRed = millis();
     SendDataRed(14);
    }
      lastBtnValRed = btnVal;
 }
  else{
    if(GetDataRed() == 14){
        digitalWrite(ledRed , HIGH);
    }
 } 



  if(IsGreenConnected && IsRedConnected == false && IsBtnConnected == false){
    if(btnVal == LOW && lastBtnValGreen == HIGH && millis() - lastBtnPressTimeGreen > 50 ){
       lastBtnPressTimeGreen = millis();
       SendDataGreen(50);
    }
    lastBtnValGreen = btnVal;
 }
 else{
     if(GetDataGreen() == 50){
        digitalWrite(ledGreen , HIGH);
    }
 }



  if(IsBtnConnected && IsRedConnected == false  && IsGreenConnected == false){
     if(btnVal == LOW && lastBtnVal == HIGH && millis() - lastBtnPressTimeBtn > 50 ){
       lastBtnPressTimeBtn = millis();
         SendDataRed(100);
         SendDataGreen(100);
      if(GetDataGreen() == 100 || GetDataRed() == 100){
         digitalWrite(ledGreen , LOW);
         digitalWrite(ledRed , LOW);
      }
    }
     lastBtnVal = btnVal; 
    
 }


 
}
