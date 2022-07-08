

#define vcc      3.3v
#define  inOut    A0
#define   C       D7
#define   B       D6
#define   A       D5
#define led       D1

void setup() {  
pinMode(inOut , OUTPUT); 
pinMode(led , OUTPUT);
pinMode(C , OUTPUT); 
pinMode(B , OUTPUT); 
pinMode(A , OUTPUT); 
Serial.begin(9600);

}

void loop() {
  int k = analogRead(inOut);
  Serial.println(k);
  analogWrite(led , k);
}
