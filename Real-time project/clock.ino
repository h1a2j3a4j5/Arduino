#include <ASCIIDic.h>

#include <NX7Seg.h>

  #define CLK_DIO   D5   

  #define LATCH_DIO D6 

  #define DATA_DIO  D7  

  nx7seg my4x7seg = nx7seg(LATCH_DIO, CLK_DIO, DATA_DIO , true); 
 
void clockSetup () {
  pinMode(LATCH_DIO, OUTPUT);

   pinMode(CLK_DIO, OUTPUT);

   pinMode(DATA_DIO, OUTPUT);

}


  void TimeReale(int min, int sec) {
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
      my4x7seg.refresh(1000);
  
 }
