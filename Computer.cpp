//Student1 Eed Estifan, eedestefan10@gmail.com, 215630351. 
//Student2 Adam Masalha, adamsoheelm@gmail.com, 217070259. 
#include "Computer.h"
#include "HWExceptions.h"
#include<algorithm>

//Constructors and destructor

Computer::Computer(int price, const std::string& manufacturer, const std::string& cpu, bool isALaptop, int numOfPorts)
    :Item(price,manufacturer ), cpu(cpu), isALaptop(isALaptop),  numOfPorts(numOfPorts) {}

Computer::~Computer() {
    for (int i = 0; i < connectedDevices.size(); i++)connectedDevices[i]->connectedComputer = NULL;
}

//private methods
   
bool Computer::addDeviceValidator(PeripheralDevice* device)const {
    if (connectedDevices.size() == numOfPorts)return false;
    for (int i = 0; i < connectedDevices.size(); i++) {
        if (typeid(*device) == typeid(*connectedDevices[i]))return false;
    }
    return true;
}

//member methods

void Computer::addDevice(PeripheralDevice* device) {
    if (addDeviceValidator(device)) {
        connectedDevices.push_back(device);
    }
    else {  
        throw ConnectError();
    }
}

void Computer::removeDevice(PeripheralDevice* device) {
    std::vector<PeripheralDevice*>& vec = this->connectedDevices;
    std::vector<PeripheralDevice*>::iterator it = find(vec.begin(), vec.end(), device);
    if (it != vec.end()) {
        vec.erase(it);
    } 
}

void Computer::printConnected()const {

    std::cout << "There are " << connectedDevices.size() << " connections to " << operator std::string()<<std::endl;
    for (int i = 0; i < connectedDevices.size(); i++) {
        std::cout << connectedDevices[i]->operator std::string() << std::endl;
    }
}

//member operators

Computer::operator std::string()const {
    return Item::operator std::string() + ", " + (isALaptop ? "Laptop, " : "Desktop, ") + cpu;
}

//getters and setters 

std::string Computer::getCpu()const {
    return cpu;
}

bool Computer::getIsALaptop()const {
    return isALaptop;
}

int Computer::getNumOfPorts()const {
    return numOfPorts;
}

void Computer::setCpu(const std::string& cpu) {
    this->cpu = cpu;
}

void Computer::setIsALaptop(bool isALaptop) {
    this->isALaptop = isALaptop;
}


