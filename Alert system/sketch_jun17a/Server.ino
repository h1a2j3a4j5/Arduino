#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
            
#include <ESP8266HTTPClient.h>
            
const char* ssid = "Hagag1";
const char* pswd = "046934910";
            
WiFiClient client;
int server_port = 80;//http
            
void wifi_Setup() {
Serial.println("wifiSetup");
WiFi.begin(ssid, pswd);
            
while (WiFi.status() != WL_CONNECTED) {
     Serial.println("trying ...");
      delay(100);
    }
      Serial.println("Connected to network");
}
            
void SendDataRed(int val) {
  HTTPClient http;
  String dataURL = "";
  dataURL += "ACT=SET&DEV=21821&CH=1";
  dataURL += "&VAL="+String(val);
  http.begin(client,"http://api.kits4.me/GEN/api.php?" + dataURL);
  int httpCode = http.GET();
  Serial.println(httpCode);
  http.end();
}


int GetDataRed() {
  int ret = -1;
  HTTPClient http;
  String dataURL = "";
  dataURL += "ACT=GET&DEV=21821&CH=1";
  http.begin(client, "http://api.kits4.me/GEN/api.php?" + dataURL);
  int httpCode = http.GET();
  Serial.println(httpCode);
  if (httpCode == HTTP_CODE_OK) {
    Serial.print("HTTP response code ");
     Serial.println(httpCode);
      String Res = http.getString();
       Serial.println(Res);
         ret = Res.toInt();
    }
   http.end();
            
   return ret;
}






void SendDataGreen(int val) {
  HTTPClient http;
  String dataURL = "";
  dataURL += "ACT=SET&DEV=21821&CH=2";
  dataURL += "&VAL="+String(val);
  http.begin(client,"http://api.kits4.me/GEN/api.php?" + dataURL);
  int httpCode = http.GET();
  Serial.println(httpCode);
  http.end();
}


int GetDataGreen() {
  int ret = -1;
  HTTPClient http;
  String dataURL = "";
  dataURL += "ACT=GET&DEV=21821&CH=2";
  http.begin(client, "http://api.kits4.me/GEN/api.php?" + dataURL);
  int httpCode = http.GET();
  Serial.println(httpCode);
  if (httpCode == HTTP_CODE_OK) {
     Serial.print("HTTP response code ");
      Serial.println(httpCode);
       String Res = http.getString();
         Serial.println(Res);
           ret = Res.toInt();
     }
    http.end();
            
    return ret;
}
