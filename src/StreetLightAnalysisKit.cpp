#include "StreetLightAnalysisKit.h"
#include <Arduino.h>

StreetLightAnalysisKit::StreetLightAnalysisKit() : lightSensor(), sdCardStorage(), wirelessTransmission("KnolPower", "EnzoKnol")
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
    int objectID = 0;
    float operationalStatusFloat = lightSensor.detectFakeLight();

    int operationalStatus = 0;
    if (operationalStatusFloat > 0.5)
    {
        operationalStatus = 1;
    }

    // Get the location
    std::pair<float, float> location = gpsSensor.getFakeLocation();

    String timestamp = "2021-01-01 00:00:00";

    // For debugging, print the data to the serial monitor
    Serial.println(String("Data: ") + objectID + ", " + operationalStatus + ", " + timestamp + ", " + location.first + ", " + location.second);

    // Transmit the data to the server
    wirelessTransmission.transmitData(objectID, operationalStatus, timestamp, location.first, location.second);
}
