#include <Arduino.h>
#include <StreetLightAnalysisKit.h>

StreetLightAnalysisKit streetLightAnalysisKit;

void setup()
{
}

void loop()
{
  streetLightAnalysisKit.analyzeStreetLight();
  delay(1000);
}
