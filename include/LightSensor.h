#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

class LightSensor
{
private:
    float intensity;

public:
    LightSensor();
    float detectLight();
};

#endif // LIGHTSENSOR_H
