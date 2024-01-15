#include "WirelessTransmission.h"
#include <WiFi.h>
#include <HTTPClient.h>

WirelessTransmission::WirelessTransmission(const char *ssid, const char *password)
{
  SSID = ssid;
  PASSWORD = password;
}

void WirelessTransmission::init()
{
  Serial.println(SSID);
  Serial.println(PASSWORD);

  WiFi.begin(SSID, PASSWORD);
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

void WirelessTransmission::transmitData(int objectID, int operationalStatus, const String &timestamp, float xCoordinate, float yCoordinate)
{
  if (isConnected())
  {
    HTTPClient http;
    http.begin("http://i493105.hera.fhict.nl/upload_light_status.php"); // Change to your server URL
    http.addHeader("Content-Type", "application/json");

    // Create a JSON object
    DynamicJsonDocument doc(1024);
    doc["OBJECTID"] = objectID;
    doc["operational_status"] = operationalStatus;
    doc["timestamp"] = timestamp;
    doc["X_coordinate"] = xCoordinate;
    doc["Y_coordinate"] = yCoordinate;

    // Serialize the JSON object to a string
    String jsonString;
    serializeJson(doc, jsonString);

    // Send the POST request
    int httpResponseCode = http.POST(jsonString);
    if (httpResponseCode > 0)
    {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    }
    else
    {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }
}

bool WirelessTransmission::isConnected()
{
  return WiFi.status() == WL_CONNECTED;
}