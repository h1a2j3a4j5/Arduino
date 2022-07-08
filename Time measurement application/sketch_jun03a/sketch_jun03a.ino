
#define  btnG D1 
#define  btnR D4
#define  LedRed D2

unsigned long StartPressTimeGreen;
unsigned long FinishPressTimeGreen;

unsigned long StartPressTimeRed;
unsigned long FinishPressTimeRed;
int resultRed , resultGreen;
int currentG = 0 , currentR = 0;
int Red [num];
int Green [num];
bool IsFlag = true;


void setup() {
pinMode(btnG, INPUT_PULLUP);
pinMode(btnR, INPUT_PULLUP);
pinMode(LedRed , OUTPUT);
Serial.begin(9600);
StartPressTimeRed = millis();
FinishPressTimeRed = millis();
}

void loop() {
   StartPressTimeRed = millis();
  if(digitalRead(btnR)==LOW){
    while(digitalRead(btnR)==LOW);
    FinishPressTimeRed=millis();
    resultRed = FinishPressTimeRed-StartPressTimeRed;
    Red[currentR] = resultRed;
    currentR++;
    Serial.println(resultRed);
    delay(50);
 }
  

    StartPressTimeGreen = millis();
  if(digitalRead(btnG)==LOW){
    while(digitalRead(btnG)==LOW);
    FinishPressTimeGreen=millis();
    resultGreen = FinishPressTimeGreen-StartPressTimeGreen;
    Green[currentG] = resultGreen;
    currentG++;
    Serial.println(resultGreen);
    delay(50);
 }


 if(currentR >= 10 && currentG >= 10 &&   IsFlag == true){
   checkRed ();
   checkGreen  ();
   IsFlag = false;
 }

}  
void checkRed () {
    Serial.println("Red button array :");
    Serial.println(" ");
     double temp;
  for (int i = 0; i < num-1; i++)
  {
    for (int j = 0; j < num - i -1; j++)
    {
      if (Red[j] > Red[j+1])
      {
        temp = Red[j];
        Red[j] = Red[j+1];
        Red[j+1] = temp;
      }
    }
  }
      for(int k = 0;k< num; k++){
      Serial.print("index:  ");
      Serial.println(k ); 
      Serial.println(Red[k]);
     }
  } 

void checkGreen  () {
  Serial.println("Green button array :");
  Serial.println(" ");
       double temp2;
  for (int i = 0; i < num-1; i++)
  {
    for (int j = 0; j < num - i -1; j++)
    {
      if (Green[j] > Green[j+1])
      {
        temp2 = Green[j];
        Green[j] = Green[j+1];
       Green[j+1] = temp2;
      }
    }
  }
      for(int k = 0;k< num; k++){
      Serial.print("index:  ");
      Serial.println(k ); 
      Serial.println(Green[k]);
     }
}
