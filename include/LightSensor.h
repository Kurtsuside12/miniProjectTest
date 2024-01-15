#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

class LightSensor
{
private:
    float intensity;

public:
    LightSensor();
    float detectLight();
    float detectFakeLight();
};

#endif // LIGHTSENSOR_H
