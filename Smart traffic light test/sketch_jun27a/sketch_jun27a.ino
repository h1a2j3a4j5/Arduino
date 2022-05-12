#define pinLed_U 7
#define pinLed_L 8
#define pinLed_D 9
#define pinLed_R 10

#define green_led 11
#define red_led 12
#define btnPedestrians 2
#define NUM 2
#define NUM_OF_LEDS 4
int Leds[NUM_OF_LEDS] = { pinLed_R ,      pinLed_D,       pinLed_L,      pinLed_U };
int LedsPedestrian [NUM] = {red_led , green_led};
bool isLedOn;
unsigned long checkTimeGreen;
unsigned long lastBtnPressTime;
int delayRed =  2000;
int delayYellow = 500;
int delayGreen = 1000;
int lastBtnVal;
int index = 0;
bool blinkOn = false;
bool isLedOnGreen;

void setup() {
  for (int k = 0; k < NUM_OF_LEDS; k++) {
    pinMode(Leds[k], OUTPUT);
    pinMode(LedsPedestrian[k], OUTPUT);
    Serial.begin(9600);
  }
  pinMode(btnPedestrians, INPUT_PULLUP);
  checkTimeGreen = millis();
  lastBtnPressTime = millis();
}

void loop() { 
  digitalWrite(red_led , HIGH);
  Serial.println("Car traffic light in action");
  togeled (Leds[0] , delayRed);
  Serial.println("RED");
  pedestrians ();
  togeled2 (Leds[1] , delayYellow);
  Serial.println("YELLOW");
  digitalWrite(Leds[0],LOW);
  digitalWrite(Leds[1],LOW);
  togeled3 (Leds[2] ,delayGreen);
  Serial.println("GREEN");
  togeledRevers ();
}



void pedestrians () {
    
    int check = digitalRead(btnPedestrians);
    if(((check == LOW)  && (lastBtnVal == HIGH)) && (millis() -  lastBtnPressTime >= 50)){    
      lastBtnPressTime = millis();   
      Serial.println("Pedestrians crossing");
      ledOff ();
      PedestrianTrafficLight ();  
      LedOn ();
      delay(1000);   
    }
    lastBtnVal = check;
}

void PedestrianTrafficLight () { 
      digitalWrite(LedsPedestrian[1],HIGH);
      delay(2000);
      digitalWrite(LedsPedestrian[1],LOW);

}

void togeled3 (int ledPinGreen , int ledDelayGreen) {
  digitalWrite(ledPinGreen , HIGH);
  delay(ledDelayGreen);
  digitalWrite(ledPinGreen , LOW);
}

void  togeled2 (int ledPinYellow , int ledDelayYellow ) {
  digitalWrite(ledPinYellow , HIGH);
  delay(ledDelayYellow);
}

void togeled (int ledPinRed , int ledDelayRed) {
  digitalWrite(ledPinRed , HIGH);
  delay(ledDelayRed);
}

void togeledRevers () {
  digitalWrite(Leds[2],LOW);
  digitalWrite(Leds[1],HIGH);
  delay(delayYellow);
  digitalWrite(Leds[1],LOW);
  digitalWrite(Leds[0],HIGH);
}

void togleled1 () {
  if(isLedOn) {
    ledOff ();
  }else{
    LedOn ();
  }
}

void LedOn () {
  digitalWrite(LedsPedestrian[0],HIGH);
  isLedOn = true; 
}

void ledOff () {
  digitalWrite(LedsPedestrian[0],LOW);
  isLedOn = false; 
}
