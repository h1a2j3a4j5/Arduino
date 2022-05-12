#define btn_G 3
#define btn_Y 4
#define btn_R 5
#define btn_B 6
#define ledPin_U 7
#define ledPin_L 8
#define ledPin_D 9
#define ledPin_R 10
#define NUMBER_OF_CHANNELS 4
#define MAX_CODE_LEN 6
#define BTN_LEN 4
int codeLen = 3;

int leds [NUMBER_OF_CHANNELS] =         {ledPin_R , ledPin_L , ledPin_D , ledPin_U};
int btns[BTN_LEN] =                     {btn_R ,     btn_G ,     btn_Y ,   btn_B};
bool isBtnPreesed[NUMBER_OF_CHANNELS] = {false ,    false ,    false    ,false};
int CorrectCode[MAX_CODE_LEN];
int pressedBtn[MAX_CODE_LEN]; 
byte codeIndex = 0;

void setup() {
for(int k = 0;k<NUMBER_OF_CHANNELS;k++){
  pinMode(leds[k],OUTPUT);
  pinMode(btns[k],INPUT_PULLUP);
}
Serial.begin(9600);
randomSeed(anaLogRead(A5));
chooseCode();
showCode();
}
void loop() {
   for(int k = 0;k<BTN_LEN;k++){
  if(digitalRead(btns[k])==LOW){
    if(isBtnPreesed[k]==false){
      pressedBtn[codeIndex] = k;
      codeIndex++;
      if(codeIndex >= codeLen){
        if(CompareAnswer()){
           finishGame();
        }else{
          tryAgain();
        }
        codeIndex = 0;
      }
  
    }
    isBtnPreesed[k] = true; 
  }else{
  isBtnPreesed[k] = false;
  }
 }
 delay(50);
}








void chooseCode(){
  for(int i = 0;i<codeLen;i++){   
    CorrectCode[i] = random(NUMBER_OF_CHANNELS);
  }
}

void showCode(){
  for(int i = 0;i<codeLen;i++){
    digitalWrite(leds[CorrectCode[i]],HIGH);
    delay(200);
    digitalWrite(leds[CorrectCode[i]],LOW);
    delay(200);
  }
}

bool CompareAnswer(){
  bool CorrectFlag = true;
  for(int k=0;k<codeLen;k++){
    if(pressedBtn[k]==CorrectCode[k]){
    } else {
      CorrectFlag=false;
      break;
    }
  }
    return CorrectFlag;
}

void finishGame(){
 

void tryAgain(){
  for(int k = 0;k<codeLen;k++){
    digitalWrite(ledPin_R ,HIGH);
    delay(100);
     digitalWrite(ledPin_R ,LOW);
    delay(100);
  }
}
