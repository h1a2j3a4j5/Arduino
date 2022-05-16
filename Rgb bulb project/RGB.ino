#define B D1
#define G D2
#define R D3

bool LedIsOn;


void ledRgbSetup () {
  pinMode(B , OUTPUT);
  pinMode(G , OUTPUT);
  pinMode(R , OUTPUT);
}

void colorTheLed (int  k ,  int s , int m) {
  analogWrite(B,k);
  analogWrite(G,s);
  analogWrite(R,m);
}



void getRGB(String hexvalue) {
    String hexstring = hexvalue;
    long number = (long) strtol( &hexstring[1], NULL, 16);
    r = number >> 16;
    g = number >> 8 & 0xFF;
    b = number & 0xFF;

    Serial.print("red is ");
    Serial.println(r);
    Serial.print("green is ");
    Serial.println(g);
    Serial.print("blue is ");
    Serial.println(b);
    if (LedIsOn) {
      colorTheLed (b,g,r);
    }
}

void LeddOff() {
  digitalWrite(B, LOW);
  digitalWrite(G, LOW);
  digitalWrite(R, LOW);
  LedIsOn = false;
}


void ChangeLedLight() {
  if (LedIsOn) {
    LeddOff();
    }
  else {
    colorTheLed (b,g,r);
    LedIsOn = true;
  }
}
