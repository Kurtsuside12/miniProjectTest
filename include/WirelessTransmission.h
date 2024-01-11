#ifndef WIRELESSTRANSMISSION_H
#define WIRELESSTRANSMISSION_H

#include <Arduino.h>
class WirelessTransmission
{
private:
    bool isConnected();

public:
    WirelessTransmission(String ssid, String password);
    void transmitData(const String &data);
};

#endif // WIRELESSTRANSMISSION_H
