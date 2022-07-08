#define B D1
#define G D2
#define R D3

void setupRgb () {
  pinMode(B , OUTPUT);
  pinMode(G , OUTPUT);
  pinMode(R , OUTPUT);
}


typedef struct  {
 int R;
 int G;
 int B;
}colors;

colors  check [3] {
  {255,255,0},
  {128,0,128},
  {128,0,0},
};

void loopLed (int k) {
  analogWrite(R,check[k].R);
  analogWrite(G,check[k].G);
  analogWrite(B,check[k].B);
}
