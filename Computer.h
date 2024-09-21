//Student1 Eed Estifan, eedestefan10@gmail.com, 215630351. 
//Student2 Adam Masalha, adamsoheelm@gmail.com, 217070259. 
#pragma once
#include "Item.h"
#include "PeripheralDevice.h"
#include<vector>
class PeripheralDevice;

class Computer : public virtual Item {
    std::string cpu;
    bool isALaptop;
    const int numOfPorts;
    std::vector<PeripheralDevice*> connectedDevices;

    bool addDeviceValidator(PeripheralDevice* device)const;

public:
    Computer(int price, const std::string& manufacturer, const std::string& cpu, bool isALaptop, int numOfPorts);
    ~Computer();

    std::string getCpu() const;
    bool getIsALaptop() const;
    void setCpu(const std::string& cpu);
    void setIsALaptop(bool isALaptop);
    int getNumOfPorts()const;

    operator std::string()const;

    void printConnected()const;
    void addDevice(PeripheralDevice* device);
    void removeDevice(PeripheralDevice* device);
};

