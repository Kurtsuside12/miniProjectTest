#ifndef STREETLIGHTANALYSISKIT_H
#define STREETLIGHTANALYSISKIT_H

#include "LightSensor.h"
#include "SDCardStorage.h"
#include "WirelessTransmission.h"
#include "GPSSensor.h"
#include <utility>
class StreetLightAnalysisKit
{
private:
    LightSensor lightSensor;
    SDCardStorage sdCardStorage;
    WirelessTransmission wirelessTransmission;
    GPSSensor gpsSensor;

public:
    StreetLightAnalysisKit();
    void analyzeStreetLight();
    bool init();
};

#endif // STREETLIGHTANALYSISKIT_H
