#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>

#include <ESP8266HTTPClient.h>
//const char* ssid = "amir";
//const char* pswd = "55555333";

WiFiClient client;
int server_port = 80;//http

void wifiRemote_Setup() {
    Serial.println("wifiSetup");
    WiFi.begin(ssid);

    while (WiFi.status() != WL_CONNECTED) {
        Serial.println("trying ...");
        delay(100);
    }
    Serial.println("Connected to network");
}
void SendData(int val) {
    HTTPClient http;
    String dataURL = "";
    dataURL += "LDR=" + String(val);
    http.begin(client, "http://55.55.55.55/?" + dataURL);
    int httpCode = http.GET();
    Serial.println(httpCode);
    http.end();
}
