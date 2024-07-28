#include "ESP8266WiFi.h"

void setup()
{
  pinMode(D4, OUTPUT);
  Serial.begin(115200);
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void loop()
{
  digitalWrite(D4, LOW);
  delay(100);
  digitalWrite(D4, HIGH);
  delay(100);
  Serial.print("Scan start ... ");
  int n = WiFi.scanNetworks();
  Serial.print(n);
  Serial.println(" for n network(s) found");
    for (int i = 0; i < n; i++)
  {
    Serial.println(WiFi.SSID(i));

    Serial.println(WiFi.BSSIDstr(i));
  }
  int n2 = WiFi.scanNetworks(true);
  Serial.print(n2);
  Serial.println(" for n2 network(s) found");
      for (int i = 0; i < n2; i++)
  {
    Serial.println(WiFi.SSID(i));

    Serial.println(WiFi.BSSIDstr(i));
  }
  int n3 = WiFi.scanNetworks(true, true);
  Serial.print(n3);
  Serial.println(" for n3 network(s) found");
  for (int i = 0; i < n3; i++)
  {
    Serial.println(WiFi.SSID(i));

    Serial.println(WiFi.BSSIDstr(i));
  }
  int n4 = WiFi.scanNetworks(false, true);
  Serial.print(n4);
  Serial.println(" for n3 network(s) found");
  for (int i = 0; i < n4; i++)
  {
    Serial.println(WiFi.SSID(i));

    Serial.println(WiFi.BSSIDstr(i));
  }
  Serial.println();

  delay(5000);
}