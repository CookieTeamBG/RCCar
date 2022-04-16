
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
 
 
const char *ssid = "";
const char *password = "";
 
ESP8266WebServer server(80);
 
uint8_t pin1=D0;
uint8_t pin2=D1;

 
bool pin1_status=false, pin2_status=false;
 
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.print(ssid);
 
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
   
  WiFi.begin(ssid,password);
 
 
  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi Connected with IP Address: ");
  Serial.println(WiFi.localIP());
 
   server.on("/",handle_OnConnect);
  server.on("/pin1on",handle_pin1on);
  server.on("/pin1off",handle_pin1off);
  server.on("/pin2on",handle_pin2on);
  server.on("/pin2off",handle_pin2off);
  server.onNotFound(handle_NotFound);
   
  server.begin();
  Serial.println("HTTP Server Started");
}
 
void loop() {
 
  if(WiFi.status()==WL_CONNECTED)
  {
    server.handleClient();
 
   
    if(pin1_status==false)
    {
      digitalWrite(pin1,LOW);
    }
    else
    {
      digitalWrite(pin1,HIGH);
    }
   
    if(pin2_status==false)
    {
      digitalWrite(pin2,LOW);
    }
    else
    {
      digitalWrite(pin2,HIGH);
    }
   
    
   
    
  }
  else
  {
    Serial.println("WiFi Disconnected!!!");
    Serial.print("Trying to establish the connection...");
     
    while(WiFi.status()!=WL_CONNECTED)
    {
      delay(1000);
      Serial.print(".");
    }
    Serial.println("");
    Serial.print("WiFi Connected with IP Address: ");
    Serial.println(WiFi.localIP());
  }
}
 
void handle_OnConnect()
{
  Serial.println("Client Connected");
  server.send(200, "text/html", HTML()); 
}
 
void handle_pin1on()
{
  Serial.println("PIN1 ON");
  pin1_status=true;
  server.send(200, "text/html", HTML());
}
 
void handle_pin1off()
{
  Serial.println("PIN1 OFF");
  pin1_status=false;
  server.send(200, "text/html", HTML());
}
 
void handle_pin2on()
{
  Serial.println("PIN2 ON");
  pin2_status=true;
  server.send(200, "text/html", HTML());
}
 
void handle_pin2off()
{
  Serial.println("PIN2 OFF");
  pin2_status=false;
  server.send(200, "text/html", HTML());
}
void handle_NotFound()
{
  server.send(404, "text/plain", "Not found");
}
 
String HTML()
{
  String msg="<!DOCTYPE html> <html>\n";
  msg+="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  msg+="<title>Control</title>\n";
  msg+="<style>html{font-family:Helvetica; display:inline-block; margin:0px auto; text-align:center;}\n";
  msg+="body{margin-top: 50px;} h1{color: #444444; margin: 50px auto 30px;} h3{color:#444444; margin-bottom: 50px;}\n";
  msg+=".button{display:block; width:80px; background-color:#f48100; border:none; color:white; padding: 13px 30px; text-decoration:none; font-size:25px; margin: 0px auto 35px; cursor:pointer; border-radius:4px;}\n";
  msg+=".button-on{background-color:#f48100;}\n";
  msg+=".button-on:active{background-color:#f48100;}\n";
  msg+=".button-off{background-color:#26282d;}\n";
  msg+=".button-off:active{background-color:#26282d;}\n";
  msg+="</style>\n";
  msg+="</head>\n";
  msg+="<body>\n";
  msg+="<h1>ESP8266 RC Car</h1>\n";
   
  if(pin1_status==false)
  {
    msg+="<p>Left: OFF</p><a class=\"button button-on\" href=\"/pin1on\">ON</a>\n";    
  }
  else
  {
    msg+="<p>Left: ON</p><a class=\"button button-off\" href=\"/pin1off\">OFF</a>\n";
  }
 
  if(pin2_status==false)
  {
    msg+="<p>Right: OFF</p><a class=\"button button-on\" href=\"/pin2on\">ON</a>\n";    
  }
  else
  {
    msg+="<p>Right: ON</p><a class=\"button button-off\" href=\"/pin2off\">OFF</a>\n";
  }
 
   
  msg+="</body>\n";
  msg+="</html>\n";
  return msg;
}
