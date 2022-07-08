#define B D1
#define G D2
#define R D3
int score = 0;
void setup() {
  
ledRgbSetup ();
ledBtnSetup ();
Serial.begin(9600);
}

void loop() {
  

int index = random(4);;
colorTheLed (index);
delay(random(500,1000));

if(isbtnPress () ) {
   if(index == 1) {
    score++;
     }
  }
   Serial.println(score);
}
