
#define led        D2  
#define   C       D7
#define   B       D6
#define   A       D5
#define inUot     A0

void setup() {
pinMode(led ,OUTPUT); 
   pinMode(A , OUTPUT);
   pinMode(B , OUTPUT);
   pinMode(C , OUTPUT);
   pinMode(inUot , INPUT);
   Serial.begin(9600);
}

void loop() {
  int num =  ReadMuxChannel();
  analogWrite(led , num);
}

int ReadMuxChannel() {
    int ret = 0;
    
    digitalWrite(C  ,LOW);
    digitalWrite(B  ,HIGH);
    digitalWrite(A  ,HIGH);    
    ret =  map(analogRead(inUot) , 0 , 1023 , 0 , 255);
    
    return ret;
}
