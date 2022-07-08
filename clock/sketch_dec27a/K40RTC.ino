#include <RTClib.h>
RTC_DS1307 rtc;


bool check;

void rtc_setup() {
    int cnt = 0;
    check = true;
    while ((!rtc.begin()) && (cnt < 5)) {
        Serial.println("RTC failed, or not present");
        delay(1000);
        cnt++;
        check = false;
   }
   if(cnt < 5 ) {
    check = true;
  }
  if (!rtc.isrunning()) {
      rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
    Serial.begin(9600);
    
}


void printUnixTime () {
  
  DateTime nowTime = rtc.now();
  Serial.println(nowTime.unixtime()); 
}





void printCurrentTime () {
  DateTime nowTime = rtc.now();

  Serial.print(nowTime.hour());
  Serial.print(":");
  Serial.print(nowTime.minute());
  Serial.print(":");
  Serial.print(nowTime.second());
  Serial.println(" ");
  
}
