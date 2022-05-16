#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h> 

IPAddress   apIP(55, 55, 55, 40); 
  const char* ssid = "YONI";
  ESP8266WebServer server(80); 


void wifi_setup () {
      WiFi.mode(WIFI_AP_STA);
      WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
      WiFi.softAP(ssid);
      server.on("/", handleRoot); 
      server.onNotFound(handleNotFound);
      server.begin(); 
}

void handleRoot() {
    String m;
if(server.hasArg("one")) {
   m = server.arg("send"); 
   getRGB(m);
}
if(server.hasArg("on/off")) {
    ChangeLedLight();
}
char html[2000]="";
  strcat(html, "<!DOCTYPE html>");
  strcat(html, "<html lang=\"en\">");
  strcat(html, "<head>");
  strcat(html, "<meta charset= \"UTF-8\" />");
  strcat(html, "<meta http-equiv=\"X-UA-Compatible\"content=\"ie=edge\">");
  strcat(html, "<meta name=viewport,content=width=device-width, initial-scale=1.0/>");
  strcat(html, "<title>Document</title>");
  strcat(html, "</head>");
  strcat(html, "<body>");
  strcat(html, "<h1>LED - COLORS</h1>");
  strcat(html, "<form action=\"\" method=\"get\">");
  strcat(html, "<P>");
  strcat(html, "<input id=\"send\" type=\"color\" value=\"\" name=\"send\">");
  strcat(html, "<input type=\"text\" id=\"result\">");
  strcat(html, "</P>");
  strcat(html,"<button type=\"submit\" name=\"one\">one</button>");
  strcat(html,"<button type=\"submit\" name=\"on/off\" value=\"0\">on/off</button>");
  strcat(html, "</form>");
  strcat(html, "</body>");
  strcat(html, "</html>");
  server.send(200, "text/html", html);
}

void handleNotFound ()  {
      String message = "File Not Foundnn";
      message += "URI: ";
      message += server.uri();
      message += "nMethod: ";
      message += (server.method() == HTTP_GET) ? "GET" : "POST";
      message += "nArguments: ";
      message += server.args();
      message += "n";
      for (uint8_t i = 0; i < server.args(); i++) {
          message += " " + server.argName(i) + ": " + server.arg(i) + "n";
      }
      server.send(404, "text/plain", message);
}

void wifi_loop() {
  server.handleClient();
  delay(10);
}
