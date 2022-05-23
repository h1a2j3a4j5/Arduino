
// libraries we use
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// הגדרה של כתובת המכשיר. אל כתובת זו ניכנס מהדפדפן
IPAddress    apIP(55, 55, 55, 55);

const char* ssid = "MyLocalServer"; //שם הרשת שיוצג
//const char* password = "88888888";// הסיסמה לרשת אם נרצה להשתמש בה

// Define a web server at port 80 for HTTP
ESP8266WebServer server(80);

void wifiServer_Setup() {
	//set-up the custom IP address
	WiFi.mode(WIFI_AP_STA);
	WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));   // subnet FF FF FF 00  

	/* You can remove the password parameter if you want the AP to be open. */
	//WiFi.softAP(ssid, password);
	WiFi.softAP(ssid);

	//וידוא הגדרת הכתובת
	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);


	server.on("/", handleRoot);//הפניה לפונקציה הראשית של הצגת דף וטיפול בו
	server.onNotFound(handleNotFound);//הפניה לפונקציה שמתמודדת עם דפים לא קיימים
	server.begin();//אתחול השרת
	Serial.println("HTTP server started");
}
void wifiServer_loop() {
	server.handleClient();//.server is defined at this tab
	delay(10);
}
void handleNotFound() {
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
void handleRoot() {
	String codeStr;
	if (server.hasArg("LDR")) {
		codeStr = server.arg("LDR");
		LdrVal = codeStr.toInt();
	}
}
