#include "Tablet.h"

Tablet::Tablet(int price, const std::string& manufacturer, const std::string& color,
    const std::string& cpu, int numOfPorts, int screenSize)
    : PeripheralDevice(price, manufacturer, color, true), // Tablet is always wireless
    Computer(price, manufacturer, cpu, false, numOfPorts), // Tablet is not a laptop
    Item(price,manufacturer),
    screenSize(screenSize) {}

int Tablet::getScreenSize() const {
    return screenSize;
}

void Tablet::setScreenSize(int screenSize) {
    this->screenSize = screenSize;
}   

Tablet:: operator std::string() const {
    return Item::operator std::string() + ", " + PeripheralDevice::getColor() + ", " + Computer::getCpu() + ", Tablet with screen size: " + std::to_string(screenSize);
}
