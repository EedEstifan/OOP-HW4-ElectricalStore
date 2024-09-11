//Student1 Eed Estifan, eedestefan10@gmail.com, 215630351. 
//Student2 Adam Masalha, adamsoheelm@gmail.com, 217070259. 
#pragma once
#include "PeripheralDevice.h"
class Keyboard :public PeripheralDevice {
    int numberOfKeys;
public:
    Keyboard(int price, const std::string& manufacturer, const std::string& color, bool isWirless, int numberOfKeys);

    int getNumberOfKeys()const;
    void setNumberOfKeys(int numberOfKeys);

    void connect(Computer& computer);
    operator std::string()const;
};

