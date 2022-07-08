#include <ASCIIDic.h>

#include <NX7Seg.h>

  #define CLK_DIO   D5   

  #define LATCH_DIO D6 

  #define DATA_DIO  D7  
  int secLeft;
  nx7seg my4x7seg = nx7seg(LATCH_DIO, CLK_DIO, DATA_DIO , true); 
 
void setupStoper () {
  pinMode(LATCH_DIO, OUTPUT);

   pinMode(CLK_DIO, OUTPUT);

   pinMode(DATA_DIO, OUTPUT);

}


void setoperLoop () {

  int mm = secLeft / 60;
  int sec = secLeft % 60;
   my4x7seg.writeDigit(s %  10 ,  3);
   my4x7seg.writeDigit(s  / 10,   2);
   my4x7seg.writeDigit(d  % 10 ,  1 , true);
   my4x7seg.writeDigit(d /  10 ,  0);
   my4x7seg.refresh(1000);

//   my4x7seg.write("-   ",4);
//   my4x7seg.writeDigit(4 , 1);
//   my4x7seg.writeDigit(2 , 2);
//   my4x7seg.writeDigit(3 , 3);
//   my4x7seg.refresh(1000);
     
}

void showTime(int min, int sec) {
      my4x7seg.writeDigit(sec % 10, 3);
      if (sec > 10) {
          my4x7seg.writeDigit(sec / 10, 2);
      } else {
          my4x7seg.writeDigit(0, 2);
      }
      my4x7seg.writeDigit(min % 10, 1, true);
      if (min > 10) {
          my4x7seg.writeDigit(min / 10, 0);
      } else {
          my4x7seg.writeDigit(0, 0);
      }
      my4x7seg.refresh(200);
  
  }


void Time (int cnt) {
  secLeft = cnt;
}

void Counter () {
  secLeft--;
}

bool isTimeFinish () {
  if(secLeft == 0)
  return  true;
  return false;
}
