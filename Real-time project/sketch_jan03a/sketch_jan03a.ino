
void setup() {
Serial.begin(9600);
wifi_setup ();
rtc_setup();
clockSetup ();
}

void loop() {
  printCurrentTime (); 
  wifi_loop();
}
