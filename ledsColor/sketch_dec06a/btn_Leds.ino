#define btn_R D4

typedef struct {
  int pin;
  int currVal;
  int lastVal;
  unsigned long checkTime;
}myBtn;

myBtn redBtn = {btn_R , 0 , 0 ,0};
  
  


void ledBtnSetup () {
  pinMode(btn_R , INPUT_PULLUP);
  redBtn.lastVal = digitalRead(redBtn.pin);
  redBtn.checkTime = millis();
}


bool isbtnPress () {
  bool ret = false;
  redBtn.currVal = digitalRead(redBtn.pin);
  if(redBtn.currVal == LOW && redBtn.lastVal == HIGH && millis() - redBtn.checkTime > 50 ){
    ret = true;
    redBtn.checkTime = millis();
  }
  redBtn.lastVal = redBtn.currVal;
  return ret;
}
