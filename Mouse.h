//Student1 Eed Estifan, eedestefan10@gmail.com, 215630351. 
//Student2 Adam Masalha, adamsoheelm@gmail.com, 217070259. 
#pragma once
#include "PeripheralDevice.h"

class Mouse :public PeripheralDevice {
    int dpi;
public:
    Mouse(int price, const std::string& manufacturer, const std::string& color, bool isWirless, int dpi);

    int getDpi()const;
    void setDpi(int dpi);

    void connect(Computer& computer);
    operator std::string()const;
};

