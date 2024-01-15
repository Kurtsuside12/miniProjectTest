#include <Arduino.h>
#include <StreetLightAnalysisKit.h>

StreetLightAnalysisKit streetLightAnalysisKit;

void setup()
{
  Serial.begin(9600);
  streetLightAnalysisKit.init();
}

void loop()
{
  streetLightAnalysisKit.analyzeStreetLight();
  delay(10000);
}
