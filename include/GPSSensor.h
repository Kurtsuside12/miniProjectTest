#ifndef GPSSENSOR_H
#define GPSSENSOR_H

#include <Arduino.h>
#include <utility>

class GPSSensor
{
private:
    float latitude;
    float longitude;

public:
    GPSSensor();
    std::pair<float, float> getLocation();
};

#endif // GPSSENSOR_H
