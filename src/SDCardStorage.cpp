#include "SDCardStorage.h"
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

const int CS = 5; // Chip Select pin for SD card
const String path = "/data.txt";

SDCardStorage::SDCardStorage()
{
    if (!SD.begin(CS))
    {
        Serial.println("SD Card initialization failed!");
        return;
    }
    Serial.println("SD Card initialized.");
}

void SDCardStorage::storeData(const String &data)
{
    File myFile;
    const char *path = "/data.txt"; // Fixed file name, change as needed

    myFile = SD.open(path, FILE_WRITE);
    if (myFile)
    {
        Serial.printf("Writing to %s\n", path);
        myFile.println(data);
        myFile.close();
        Serial.println("Write completed.");
    }
    else
    {
        Serial.println("Error opening file for writing.");
    }
}

String SDCardStorage::readData()
{
    File myFile;
    String data = "";

    myFile = SD.open(path.c_str());
    if (myFile)
    {
        Serial.printf("Reading from %s\n", path.c_str());
        while (myFile.available())
        {
            data += (char)myFile.read();
        }
        myFile.close();
    }
    else
    {
        Serial.println("Error opening file for reading.");
    }
    return data;
}

void SDCardStorage::wipeData()
{
    if (SD.remove(path.c_str()))
    {
        Serial.printf("File %s deleted successfully.\n", path.c_str());
    }
    else
    {
        Serial.println("Error deleting file.");
    }
}
