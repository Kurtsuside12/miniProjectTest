#include "LightSensor.h"
#include <Arduino.h>

const int LIGHT_SENSOR_PIN = 34; // Adjust this to the pin used for the light sensor

LightSensor::LightSensor()
{
    // Initialize the light sensor pin as an input
    pinMode(LIGHT_SENSOR_PIN, INPUT);
}

float LightSensor::detectLight()
{
    // Read the value from the light sensor
    int sensorValue = analogRead(LIGHT_SENSOR_PIN);

    // Convert the reading to a more useful value, like intensity
    // This conversion will depend on the specific sensor and your requirements
    // For now, we'll just map it to a 0.0 - 1.0 range
    intensity = map(sensorValue, 0, 4095, 0, 1000) / 1000.0;

    return intensity;
}
