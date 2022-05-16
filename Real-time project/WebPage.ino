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
  int dd, mm, yy, hh, ii, sc;
  if (server.hasArg("adjust")) {
    dd = server.arg("dd").toInt();
    mm = server.arg("mm").toInt();
    yy = server.arg("yyyy").toInt();
    hh = server.arg("hour").toInt();
    ii = server.arg("min").toInt();
    sc = server.arg("sec").toInt();
    adjustClock(dd,mm,yy,hh,ii,sc);
  }

  
  char html[2000]="";
  strcat(html, "<html>");
  strcat(html, "<head>");
  strcat(html, "<meta charset='UTF-8'>");
  strcat(html, "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
  strcat(html, "<meta http-equiv=\"X-UA-Compatible\" content=\"ie=edge\">");
  strcat(html, "<title>My Smart clock</title>");
  strcat(html, "<style>");
  strcat(html, "button{ padding: 10px; }");
  strcat(html, "</style>");

  strcat(html, "</head>");
  strcat(html, "<body>");
  strcat(html, "<h1>Clock Adjust</h1>");
  strcat(html, "<form action = \"\" method = \"get\">");
  strcat(html, "<p>");
  strcat(html, "Date:");
  strcat(html, "<input name = \"dd\" type = \"text\"");
  strcat(html, "placeholder = \"dd\" / >");
  strcat(html, "-");
  strcat(html, "<input name = \"mm\" type = \"text\"");
  strcat(html, "placeholder = \"mm\" / >");
  strcat(html, "-");
  strcat(html, "<input name = \"yyyy\" type = \"text\"");
  strcat(html, "placeholder = \"yyyy\" / >");
  strcat(html, "</p>");
  strcat(html, "");
  strcat(html, "<p>");
  strcat(html, "Time:");
  strcat(html, "<input name = \"hour\" type = \"text\"");
  strcat(html, "placeholder = \"hour\" / >");
  strcat(html, ":");
  strcat(html, "<input name = \"min\" type = \"text\"");
  strcat(html, "placeholder = \"min\" / >");
  strcat(html, ":");
  strcat(html, "<input name = \"sec\" type = \"text\"");
  strcat(html, "placeholder = \"sec\" / >");
  strcat(html, "</p>");
  strcat(html, "");
  strcat(html, "<button name='adjust'>adjust</button>");
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
