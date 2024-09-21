//Student1 Eed Estifan, eedestefan10@gmail.com, 215630351. 
//Student2 Adam Masalha, adamsoheelm@gmail.com, 217070259. 
#pragma once
#include "Computer.h"

class Computer;

class PeripheralDevice :public virtual Item {
    friend class Computer;
    std::string color;
    bool isWirless;
    Computer* connectedComputer=NULL;
public:
    PeripheralDevice(int price, const std::string& manufacturer, const std::string& color, bool isWirless);
    virtual ~PeripheralDevice();

    virtual void connect(Computer& computer) ;
    void disconnect();

    virtual operator std::string() const;

    void setColor(const std::string& color);
    void setIsWirless(bool isWirless);
    std::string getColor()const;
    bool getIsWirless()const;

};

