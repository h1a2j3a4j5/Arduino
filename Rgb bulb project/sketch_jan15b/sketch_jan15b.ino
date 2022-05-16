
int r,g,b;


void setup() {
  ledRgbSetup ();
  Serial.begin(9600);
  wifi_setup ();
}

void loop() {
wifi_loop();
}
