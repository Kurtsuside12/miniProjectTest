#ifndef WIRELESSTRANSMISSION_H
#define WIRELESSTRANSMISSION_H

#include <Arduino.h>
class WirelessTransmission
{
private:
    bool isConnected();

    String SSID;
    String PASSWORD;

public:
    WirelessTransmission(String ssid, String password);
    void transmitData(const String &data);
    void init();
};

#endif // WIRELESSTRANSMISSION_H
