#ifndef STREETLIGHTANALYSISKIT_H
#define STREETLIGHTANALYSISKIT_H

#include "LightSensor.h"
#include "SDCardStorage.h"

class StreetLightAnalysisKit
{
private:
    LightSensor lightSensor;
    SDCardStorage sdCardStorage;

public:
    StreetLightAnalysisKit();
    void analyzeStreetLight();
};

#endif // STREETLIGHTANALYSISKIT_H
