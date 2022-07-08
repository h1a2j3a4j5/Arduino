#include <ASCIIDic.h>

#include <NX7Seg.h>

  #define CLK_DIO   D5   

  #define LATCH_DIO D6 

  #define DATA_DIO  D7  
  
  nx7seg my4x7seg = nx7seg(LATCH_DIO, CLK_DIO, DATA_DIO , true); 
   
void setupStoper () {
   pinMode(LATCH_DIO, OUTPUT);
   pinMode(CLK_DIO, OUTPUT);
   pinMode(DATA_DIO, OUTPUT);
}

void Time () {
  
  DateTime nowTime = rtc.now();
  my4x7seg.writeDigit(nowTime.second()%10, 3);
  my4x7seg.writeDigit(nowTime.second()/10, 2);
  my4x7seg.writeDigit(nowTime.minute()%10, 1 , true);
  my4x7seg.writeDigit(nowTime.minute()/10, 0);
  
  my4x7seg.refresh(1000);
 
}
