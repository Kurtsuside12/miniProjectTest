#include <Arduino.h>
#include <TinyGPSPlus.h>
#include <GPSSensor.h>
static const uint32_t GPSBaud = 4800;
TinyGPSPlus gps;
GPSSensor::GPSSensor()
{
  latitude = 0;
  longitude = 0;
}

std::pair<float, float> GPSSensor::getLocation()
{
  while (Serial.available() > 0)
    if (gps.encode(Serial.read()))
    {
      displayInfo();
      return std::make_pair(gps.location.lat(), gps.location.lng());
    }
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while (true)
      ;
  }
}

void displayInfo()
{
  Serial.print(F("Location: "));
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  }
  else
  {
    Serial.print(F("INVALID"));
  }
}

std::pair<float, float> GPSSensor::getFakeLocation()
{
  latitude = 51.4416;
  longitude = 5.4697;
  return std::make_pair(latitude, longitude);
}