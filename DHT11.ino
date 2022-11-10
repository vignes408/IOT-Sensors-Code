#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup(){
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  dht.begin();

}
void loop (){
  delay(2000);
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
