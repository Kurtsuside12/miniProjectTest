#include "GPSSensor.h"

GPSSensor::GPSSensor()
{
    latitude = 0;
    longitude = 0;
}

std::pair<float, float> GPSSensor::getLocation()
{
}

std::pair<float, float> GPSSensor::getFakeLocation()
{
    latitude = 51.4416;
    longitude = 5.4697;
    return std::make_pair(latitude, longitude);
}