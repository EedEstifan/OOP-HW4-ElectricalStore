//Student1 Eed Estifan, eedestefan10@gmail.com, 215630351. 
//Student2 Adam Masalha, adamsoheelm@gmail.com, 217070259. 

#pragma once
#include<iostream>
#include<string>
#define ID 215630351

class Item {
    static int nextItemID;

    int price;
    std::string manufacturer;
    int id;

public:
    static bool itemPtrCompare(Item* item1, Item* item2);

    Item(int price = 0,const std::string& manufacturer = "~");
    virtual ~Item();

    int getPrice()const;
    void setPrice(int price);
    int getId()const;
    std::string getManufacturer()const;
    void setManufacturer(const std::string& manufacturer);

    virtual operator std::string()const = 0;
    bool operator==(const Item& other)const;
};

