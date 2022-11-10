#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int trig = 2;
int echopin = 3;
float duration,Distanceincm,Distanceininch;
int led = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(led,OUTPUT);
  Serial.println("DHT11 test!");
  dht.begin();
}
void loop()
{
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
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  float hif = dht.computeHeatIndex(t,h,false);
  Serial.print("Humidity:");
  Serial.println(h);
  Serial.print(" %");
  Serial.print("Temperature:");
  Serial.print(t);
  Serial.println("c");

}
