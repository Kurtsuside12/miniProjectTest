#include "StreetLightAnalysisKit.h"
#include <Arduino.h>

StreetLightAnalysisKit::StreetLightAnalysisKit() : lightSensor(), sdCardStorage()
{
    // Initialize any necessary components here if needed
}

void StreetLightAnalysisKit::analyzeStreetLight()
{
    // Detect the light intensity
    float lightIntensity = lightSensor.detectLight();

    // Prepare the data to be stored
    String data = "Light Intensity: " + String(lightIntensity);

    // Store the data to the SD card
    sdCardStorage.storeData(data);

    // For debugging, print the data to the serial monitor
    Serial.println(data);
}
