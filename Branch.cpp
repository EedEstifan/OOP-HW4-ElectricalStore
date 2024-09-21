//Student1 Eed Estifan, eedestefan10@gmail.com, 215630351. 
//Student2 Adam Masalha, adamsoheelm@gmail.com, 217070259. 
#include<iostream>
#include "Branch.h"

int Branch::findItemIndex(int id, int *newPos)const {
    int low = 0;
    int high = static_cast<int>(catalog.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (catalog[mid]->getId() == id) {
            return mid; // Found the item
        }
        else if (catalog[mid]->getId() < id) {
            low = mid + 1; // Search in the right half
        }
        else {
            high = mid - 1; // Search in the left half
        }
    }

    if(newPos!=NULL)
    *newPos = low; // Position where the new item should be inserted
    return -1; // Item not found
}

Branch::Branch(const std::string& location, int capacity) :location(location), capacity(capacity), totalValue(0){}

void Branch::addItem(Item* item) {
    int pos;
    if (catalog.size() == capacity)throw FullCatalogError();
    if (findItemIndex(item->getId(),&pos) != -1) throw ExistingItemError();
    catalog.insert(catalog.begin()+pos,item);
    totalValue += item->getPrice();
}

Item* Branch::removeItem(int id) {
    int i = findItemIndex(id);
    if (i == -1)throw NonExistingItemError();
    Item* item = catalog[i];
    catalog.erase(catalog.begin() + i);
    totalValue -= item->getPrice();
    return item;
}

std::string Branch::getLocation() const {
    return location;
}

const std::vector<Item*> Branch::getCatalog()const {
    return catalog;
}

Branch::~Branch() {
    for (int i = 0; i < catalog.size(); ++i)delete catalog[i];
}

int Branch::getTotalValue() const {
    return totalValue;
}

void Branch::printBranch(void(*printFunc)(const Branch&))const {
    std::cout << location << " : Item count: "<< catalog.size()<< ", Total Value: "<< totalValue << std::endl;
    printFunc(*this);
}