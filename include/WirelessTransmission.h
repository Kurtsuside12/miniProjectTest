#ifndef WIRELESSTRANSMISSION_H
#define WIRELESSTRANSMISSION_H

#include <Arduino.h>
#include <ArduinoJson.h>
class WirelessTransmission
{
private:
    bool isConnected();

    const char *SSID;
    const char *PASSWORD;

public:
    WirelessTransmission(const char *ssid, const char *password);
    void transmitData(int objectID, int operationalStatus, const String &timestamp, float xCoordinate, float yCoordinate);
    void init();
};

#endif // WIRELESSTRANSMISSION_H
