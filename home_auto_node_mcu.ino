#ifdef ENABLE_DEBUG
#define DEBUG_ESP_PORT Serial
#define NODEBUG_WEBSOCKETS
#define NDEBUG
#endif
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "SinricPro.h"
#include "SinricProSwitch.h"
#include <map>
#define WIFI_SSID      "tj"
#define WIFI_PASS      "12345678"
#define APP_KEY        "1bb7330c-77a3-442b-bcb9-7d437528272d"
#define APP_SECRET     "09e8b454-f477-45c9-bf17-7f98a68f974d-380c775e-d51c-4f4f-89a4-4eb7c8cc2be5"

#define device_ID_1    "62c7bb2a0aec232058f7c350"
#define device_ID_2    "62c7bb46ad95bfbcdf3820c4"
#define device_ID_3    "62c7bc03ad95bfbcdf3821ab"
#define device_ID_4""
#define RelayPin1 5
#define RelayPin2 4
#define RelayPin3 14
#define RelayPin4 12

#define wifiLed 16
#define BAUD_RATE 9600
#define DEBOUNCE_TIME 250

typedef struct {
  int relayPIN;
} deviceConfig_t;

std::map<String, deviceConfig_t>devices = {
  //{deviceID, {relayPIN, flipSwitchPIN}}
  {device_ID_1, {RelayPin1}},
  {device_ID_2, {RelayPin2}},
  {device_ID_3, {RelayPin3}},
  {device_ID_4, {RelayPin4}}
};

void setupRelays() {
  for (auto &device : devices) {
    int relayPIN = device.second.relayPIN;
    pinMode(relayPIN, OUTPUT);
    digitalWrite(relayPIN, HIGH);

  }


}
bool onPowerState(String deviceId, bool &state)
{
  Serial.printf("%s: %s\r\n", deviceId.c_str(), state ? "on" : "off");
  int relayPIN = devices[deviceId].relayPIN;
  digitalWrite(relayPIN, !state);
  return true;
}
void setupWiFi() {
  Serial.print("\r\n[Wifi]: Connecting");
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.printf(".");
    delay(250);
  }
  digitalWrite(wifiLed, LOW);
  Serial.printf("connected!\r\n[WiFi]: IP-address is %s\r\n", WiFi.localIP().toString().c_str());
}

void setupSinricPro()
{
  for (auto &device : devices)
  {
    const char *deviceId = device.first.c_str();
    SinricProSwitch &mySwitch = SinricPro[deviceId];
    mySwitch.onPowerState(onPowerState);
  }
  SinricPro.begin(APP_KEY, APP_SECRET);
  SinricPro.restoreDeviceStates(true);
}
void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(wifiLed, OUTPUT);
  digitalWrite(wifiLed, HIGH);
  setupRelays();
  setupWiFi();
  setupSinricPro();
}
void loop()
{
  SinricPro.handle();
}
