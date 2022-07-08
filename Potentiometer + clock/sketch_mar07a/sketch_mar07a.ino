#include <ASCIIDic.h>

#include <NX7Seg.h>

#define  IN       D4
#define   C       D7
#define   B       D6
#define   A       D5
#define inUot     A0



#define CLK_DIO   D5   

#define LATCH_DIO D6 

#define DATA_DIO  D7  
  
nx7seg my4x7seg = nx7seg(LATCH_DIO, CLK_DIO, DATA_DIO , true); 

void setup() {
   pinMode(IN , OUTPUT);
   pinMode(A , OUTPUT);
   pinMode(B , OUTPUT);
   pinMode(C , OUTPUT);
   pinMode(LATCH_DIO, OUTPUT);
   pinMode(CLK_DIO, OUTPUT);
   pinMode(DATA_DIO, OUTPUT);
   pinMode(inUot , INPUT);
   Serial.begin(9600);
}

void loop() {

 my4x7seg.writeDigit(ReadMuxChannel()  ,  0);
 my4x7seg.refresh(1000);
 Serial.println(ReadMuxChannel());
 
}




int ReadMuxChannel() {
    int ret = 0;
    
    digitalWrite(C  ,LOW);
    digitalWrite(B  ,HIGH);
    digitalWrite(A  ,HIGH);    
    ret =  map(analogRead(inUot) , 0 , 1023 , 1 , 8);
    
    return ret;
}
