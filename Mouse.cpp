//Student1 Eed Estifan, eedestefan10@gmail.com, 215630351. 
//Student2 Adam Masalha, adamsoheelm@gmail.com, 217070259. 
#include "Mouse.h"
#include<string>

Mouse::Mouse(int price, const std::string& manufacturer, const std::string& color, bool isWirless, int dpi)
    :PeripheralDevice(price, manufacturer, color, isWirless),Item(price, manufacturer), dpi(dpi) {}

int Mouse::getDpi() const {
    return dpi;
}

void Mouse::setDpi(int dpi) {
    this->dpi = dpi;
}

Mouse::operator std::string()const {
    return PeripheralDevice::operator std::string() + ", Mouse with dpi : " + std::to_string(dpi);
}

void Mouse::connect(Computer& computer) {
    //if(computer.ad)
    std::cout << "Connecting a mouse" << std::endl;
    PeripheralDevice::connect(computer);
}

