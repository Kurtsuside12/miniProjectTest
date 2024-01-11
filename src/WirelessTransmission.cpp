#include "WirelessTransmission.h"
#include <WiFi.h>

WirelessTransmission::WirelessTransmission(String ssid, String password)
{
  SSID = ssid;
  PASSWORD = password;
}

void WirelessTransmission::init()
{
  WiFi.begin(SSID.c_str(), PASSWORD.c_str());
  Serial.print("Connecting to ");
  Serial.print(SSID);
  Serial.println("...");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected to ");
  Serial.println(SSID);
}

void WirelessTransmission::transmitData(const String &data)
{
  if (isConnected())
  {
    Serial.println("Transmitting data...");
    WiFiClient client;
    const int port = 80;
    if (!client.connect("https://i493105.hera.fhict.nl/upload_light_status.php", port))
    {
      Serial.println("Connection to server failed!");
      return;
    }

    // post data
    client.println(data.length());
    client.println();
    client.println(data);
    client.println();

    Serial.println("Data transmitted.");
    Serial.println(data);
  }
}

bool WirelessTransmission::isConnected()
{
  return WiFi.status() == WL_CONNECTED;
}