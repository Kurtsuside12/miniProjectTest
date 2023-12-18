#ifndef SDCARDSTORAGE_H
#define SDCARDSTORAGE_H

#include <Arduino.h>

class SDCardStorage
{
private:
    String storageCapacity;

public:
    SDCardStorage();
    void storeData(const String &data);
    String readData();
    void wipeData();
};

#endif // SDCARDSTORAGE_H
