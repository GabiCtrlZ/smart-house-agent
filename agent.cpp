#include <Servo.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "SSID"; // should be changed before uploading code to agents
const char* pass = "PASS"; // should be changed before uploading code to agents
const char* name = "NAME"; // name of the agent, should be s
bool state = false;

ESP8266WebServer server(80);
Servo myservo;

void setup(void){
  Serial.begin(115200);
  Serial.println(".");
  
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/turn", [](){
    Serial.print("state is: ");
    Serial.println(String(state));
    turn();
    Serial.print("changed state to: ");
    Serial.println(String(state));
    server.send(200, "text/html", String(state));
  });

  server.on("/state", [](){
    Serial.print("getting state: ");
    Serial.println(String(state));
    server.send(200, "text/html", String(state));
  });
  
    server.on("/who-am-i", [](){
    Serial.print("healthz requested");
    server.send(200, "text/html", String(name));
  });

    server.on("/healthz", [](){
    Serial.print("healthz requested");
    server.send(200, "text/html", "alive");
  });

  server.begin();
  Serial.println("HTTP server started");
  
  myservo.attach(D5);   // Servo attached to D5 pin
  myservo.write(180);
  delay(200);
  myservo.detach();
}
 
void loop(void){
  server.handleClient();
}

void turn(){
  myservo.attach(D5);
  myservo.write(115);
  delay(200);
  myservo.write(180);
  delay(200);
  myservo.detach();
  state = !state;
}

String formater(String main, String toChange[]) {
  String output = main;
  for (int i = 1; i <= sizeof(toChange); i++) {
    String replaceValue = "$" + String(i);
    output.replace(replaceValue, toChange[i - 1]);
  }
  return output;
}