//Student1 Eed Estifan, eedestefan10@gmail.com, 215630351. 
//Student2 Adam Masalha, adamsoheelm@gmail.com, 217070259. 
#include "PeripheralDevice.h"

PeripheralDevice::operator std::string() const {
    return Item::operator std::string() + "," + (isWirless ? " Wireless, " : " Wired, ") + color;
}

PeripheralDevice::PeripheralDevice(int price, const std::string& manufacturer, const std::string& color, bool isWirless)
    :Item( price,manufacturer ), color(color), isWirless(isWirless),  connectedComputer(NULL) {}

PeripheralDevice::~PeripheralDevice() {
    disconnect();
}

void PeripheralDevice::setColor(const std::string& color) {
    this->color = color;
}

void PeripheralDevice::setIsWirless(bool isWirless) {
    this->isWirless = isWirless;
}

std::string PeripheralDevice::getColor() const {
    return color;
}

bool PeripheralDevice::getIsWirless() const {
    return isWirless;
}

void PeripheralDevice::connect(Computer& computer) {
    std::cout << std::string(*this) << " is connecting to computer: " << std::string(computer) << std::endl;
    if (connectedComputer!=NULL && connectedComputer->getId() == computer.getId()) {return; }
    else {
        try {
            computer.addDevice(this);//throws exception if couldnt add device
        }
        catch (std::exception&) {
            throw;
        }
        if (connectedComputer != NULL)disconnect();
        connectedComputer = &computer;
    }


}

void PeripheralDevice::disconnect() {
    if (connectedComputer == NULL) return;
    connectedComputer->removeDevice(this);
    connectedComputer = NULL;
}
