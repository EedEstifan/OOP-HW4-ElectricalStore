//Student1 Eed Estifan, eedestefan10@gmail.com, 215630351. 
//Student2 Adam Masalha, adamsoheelm@gmail.com, 217070259. 
#pragma once
#include<iostream>
#include "HWExceptions.h"
#include "Item.h"
#include<vector>
#include "MainOffice.h"

class Branch {
    //friend void MainOffice::addBranch(const std::string& location, int capacity);
    friend class MainOffice;
    std::vector<Item*>catalog;
    const int capacity;
    const std::string location;
    int totalValue;
    int findItemIndex(int id, int* newPos=NULL)const;

public:
    Branch(const std::string& location = "~", int capacity = 0);
    //Copy Constructor!!!!
    ~Branch();

    void addItem(Item* item);
    Item* removeItem(int id);

    std::string getLocation()const;
    const std::vector<Item*> getCatalog()const;
    int getTotalValue() const;

    template<typename T>
    T* giveMeFinest(T* item) const {
        int maxPrice = -1, price;
        T* maxItem = nullptr, * currentItem;

        // Use const_iterator for a const member function
        for (std::vector<Item*>::const_iterator it = catalog.begin(); it != catalog.end(); ++it) {
            if (currentItem = dynamic_cast<T*>(*it)) {
                price = (*it)->getPrice();
                if (maxItem == nullptr) {
                    maxItem = currentItem;
                    maxPrice = price;
                }
                else {
                    if (price > maxPrice) {
                        maxItem = currentItem;
                        maxPrice = price;
                    }
                }
            }
        }

        if (maxItem == nullptr) throw NoneExistingItemTypeError();
        return maxItem;
    }

    void printBranch(void(*printFunc)(const Branch&))const;

};