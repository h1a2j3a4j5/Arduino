#define A1       D5
#define B2       D6
#define C3       D7
#define inUot   A0
#define ledRed  D1

typedef struct {
  int C;
  int B;
  int A;
}MuxChanel;

MuxChanel chnls [8] = {
  {LOW ,LOW , LOW },
  {LOW ,LOW , HIGH},
  {LOW ,HIGH , LOW},
  {LOW ,HIGH , HIGH},
  {HIGH ,LOW , LOW},
  {HIGH ,LOW , HIGH},
  {HIGH , HIGH , LOW},
  {HIGH ,HIGH , HIGH},
};

void setup() {
     pinMode(A1 , OUTPUT);
     pinMode(B2 , OUTPUT);
     pinMode(C3 , OUTPUT);
     pinMode(ledRed , OUTPUT); 
     pinMode(inUot , INPUT);

     Serial.begin(9600);
}

void loop() {
 Serial.println("Vrx");
 Serial.println(ReadMuxChannel(4));
 delay(1000);
 Serial.println();
 Serial.println("analog");
 Serial.println(ReadMuxChannel(3));
 delay(1000);
 Serial.println();
}


int ReadMuxChannel(int channel) {
   int ret = 0;

    digitalWrite(A1  , chnls[channel].A);
    digitalWrite(B2  ,chnls [channel].B);
    digitalWrite(C3  , chnls[channel].C);
    
   ret = analogRead(inUot);
  return ret;
}
