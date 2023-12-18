#ifndef WIRELESSTRANSMISSION_H
#define WIRELESSTRANSMISSION_H

class WirelessTransmission
{
private:
    String connectionType; // {"WiFi", "LoRaWAN"}

public:
    WirelessTransmission();
    void transmitData(const String &data);
    bool isConnected();
};

#endif // WIRELESSTRANSMISSION_H
