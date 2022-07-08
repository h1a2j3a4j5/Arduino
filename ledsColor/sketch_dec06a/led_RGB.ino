#define B D1
#define G D2
#define R D3
typedef struct {
  int r;
  int g;
  int b;
}color;
color clrs [4] = {
  {250,    0  , 0} ,
  {255 ,   0 ,  0} ,
  {0 ,    255 , 0} ,
  {255 ,   15 , 0},
  };

void ledRgbSetup () {
  pinMode(B , OUTPUT);
  pinMode(G , OUTPUT);
  pinMode(R , OUTPUT);
}

void colorTheLed (int clrIndex) {
  analogWrite(R , clrs[clrIndex].r);
  analogWrite(G , clrs[clrIndex].g);
  analogWrite(B , clrs[clrIndex].b);
}
