void setup() {
  setupRgb ();

}

void loop() {
 int x = random(3);
loopLed (x);

delay(random(500));

}
