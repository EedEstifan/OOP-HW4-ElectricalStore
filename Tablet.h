#pragma once
#include "PeripheralDevice.h"
#include "Computer.h"

class Tablet :public PeripheralDevice, public Computer {
    int screenSize;
public:
    Tablet(int price, const std::string& manufacturer, const std::string& color,
        const std::string& cpu, int numOfPorts, int screenSize);
    int getScreenSize() const;
    void setScreenSize(int screenSize);
    virtual operator std::string() const;
};

