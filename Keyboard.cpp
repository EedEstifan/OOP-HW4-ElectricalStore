//Student1 Eed Estifan, eedestefan10@gmail.com, 215630351. 
//Student2 Adam Masalha, adamsoheelm@gmail.com, 217070259. 
#include "Keyboard.h"

Keyboard::Keyboard(int price, const std::string& manufacturer, const std::string& color, bool isWirless, int numberOfKeys)
    :PeripheralDevice(price, manufacturer, color, isWirless), Item(price, manufacturer), numberOfKeys(numberOfKeys) {}

int Keyboard::getNumberOfKeys() const {
    return numberOfKeys;
}

void Keyboard::setNumberOfKeys(int numberOfKeys) {
    this->numberOfKeys = numberOfKeys;
}

Keyboard::operator std::string()const {
    return PeripheralDevice::operator std::string() + ", Keyboard with " + std::to_string(numberOfKeys) + " keys";
}

void Keyboard::connect(Computer& computer) {
    std::cout << "Connecting a keyboard" << std::endl;
    PeripheralDevice::connect(computer);
}


