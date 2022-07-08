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


char sort[10]= "";
      


char html[2000]="";
strcat(html,"      <!DOCTYPE html>\n");
strcat(html,"      <html lang=\"en\">\n");
strcat(html,"      <head>\n");
strcat(html,"      <meta charset=\"UTF-8\">\n");
strcat(html,"      <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
strcat(html,"      <title>Document</title>\n");
strcat(html,"      </head>\n");
strcat(html,"      <body>\n");
strcat(html,"      <h1>RED</h1>\n");
strcat(html,"      \n");
itoa(Red[0] ,sort  ,10);
strcat(html,sort);
strcat(html,"     <br/>\n");
itoa(Red[1] , sort,10);
strcat(html,sort);
strcat(html,"     <br/>\n");
itoa(Red[2] , sort,10);
strcat(html,sort);
strcat(html,"      <br/>\n");
itoa(Red[3] , sort,10);
strcat(html,"      <br/>\n");
itoa(Red[4] , sort,10);
strcat(html,sort);
strcat(html,"     <br/>\n");
itoa(Red[5] , sort,10);
strcat(html,sort);
strcat(html,"     <br/>\n");
itoa(Red[6] , sort,10);
strcat(html,"      <br/>\n");
itoa(Red[7] , sort,10);
strcat(html,sort);
strcat(html,"     <br/>\n");
itoa(Red[8] , sort,10);
strcat(html,sort);
strcat(html,"      <br/>\n");
itoa(Red[9] , sort,10);
strcat(html,sort);
strcat(html, "</form>");
strcat(html,"</body>\n");
strcat(html,"</html>");
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
