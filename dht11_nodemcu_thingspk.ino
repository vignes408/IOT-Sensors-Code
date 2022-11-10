#include <DHT.h>
#include<ESP8266WiFi.h>
String apiKey = "H38TEGNC0XKW43BB";
const char *ssid = "tj";
const char *pass = "12345678";
const char* server = "api.thingspeak.com";
#define DHTPIN 0
DHT dht(DHTPIN,DHT11);
WiFiClient client;
int buzzer = 4;
int trig = 0;
int echopin = 12;
float duration,Distanceincm,Distanceininch;
int led = 16;


void setup(){

  Serial.begin(115200);
  delay(10);
  dht.begin();
  Serial.println("connecting to");
  Serial.println(ssid);
  WiFi.begin(ssid,pass);
  while (WiFi.status() != WL_CONNECTED);
  {
    delay(500);
    Serial.print(".");
     
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.begin(115200);
  pinMode(trig,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  
  
}
void loop(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if(isnan(h)|| isnan(t))
  {
    Serial.println("Failed to read from dht sensor !");
    return;
  }
  if(client.connect(server,80))
  {
    String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(t);
    postStr += "&field2=";
    postStr += String(h);
    postStr += "\r\n\r\n";
    client.print("POST/update HTTP/1.1\n");
    client.print("Host: api.thinspeak.com\n");
    client.print("Connection:close\n");
    client.print("X-THINGSPEAKAPIKEY:"+ apiKey +"\n");
    client.print("Content-Type:application/x-www-form-urlencoded\n");
    client.print("Content-length:");
    client.print("postStr.length()");
    client.print("\n\n");
    client.print(postStr);

    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print("degrees Celcius, Humidity: ");
    Serial.print(h);
    Serial.print("%. Send to Thingspeak.");  

  }
  client.stop();
  Serial.print("Waiting...");
  delay(1000);
  digitalWrite(trig,HIGH);
  delay(15);
  digitalWrite(trig,LOW);
  duration = pulseIn(echopin,HIGH);
  Distanceincm = duration / 58;
  Distanceininch =  duration / 148;
  Serial.print("Distance in cm = ");
  Serial.print(Distanceincm);
  Serial.print(" Distance in inches = ");
  Serial.println(Distanceininch);
  delay(500);
  if(Distanceincm <=10)
  {
   digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
  if(Distanceincm>=140)
  {
    digitalWrite(buzzer,HIGH);
  }
  else
  {
    digitalWrite(buzzer,LOW);
  }
}
