#include "StreetLightAnalysisKit.h"
#include <Arduino.h>

StreetLightAnalysisKit::StreetLightAnalysisKit() : lightSensor(), sdCardStorage(), wirelessTransmission(SSID, PASSWORD)
{
    // Initialize any necessary components here if needed
}

bool StreetLightAnalysisKit::init()
{
    // Initialize any necessary components here if needed
    wirelessTransmission.init();
    return true;
}

void StreetLightAnalysisKit::analyzeStreetLight()
{
    // Detect the light intensity
    float lightIntensity = lightSensor.detectLight();

    // Prepare the data to be stored
    String data = String(lightIntensity);

    // Get the location
    std::pair<float, float> location = gpsSensor.getLocation();
    data += "," + String(location.first) + "," + String(location.second);

    // Store the data to the SD card
    sdCardStorage.storeData(data);

    // For debugging, print the data to the serial monitor
    Serial.println(data);

    // Transmit the data to the server
    wirelessTransmission.transmitData(data);
}
