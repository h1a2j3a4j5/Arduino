/*
 Name:		TwoWemosTalkLocally.ino
 Created:	5/23/2022 5:31:38 PM
 Author:	amird
*/

#define LdrPin A0
#define LedPin D4
bool IsLdrConnected;
#define LdrConnectedPin D1

int LdrVal;

// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(LdrConnectedPin, INPUT_PULLUP);
    IsLdrConnected = (digitalRead(LdrConnectedPin) == LOW) ? true : false;
    if (!IsLdrConnected) {
        wifiServer_Setup();
        LdrVal = 0;
    } else {
        wifiRemote_Setup();
    }
}

// the loop function runs over and over again until power down or reset
void loop() {
    if (!IsLdrConnected) {
        wifiServer_loop();
        analogWrite(LedPin, LdrVal);
    } else {
        int LdrVal = analogRead(LdrPin);
        int LedValue = map(LdrVal, 0, 1023, 0, 255);
        SendData(LedValue);
    }
    delay(500);
}
