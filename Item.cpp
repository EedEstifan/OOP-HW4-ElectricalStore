//Student1 Eed Estifan, eedestefan10@gmail.com, 215630351. 
//Student2 Adam Masalha, adamsoheelm@gmail.com, 217070259. 
#include "Item.h"
#include<iostream>

int Item::nextItemID = 1;

Item::operator std::string() const {
    return "id " + std::to_string(id) + ": " + manufacturer + ", " + std::to_string(price) + "$";
}

Item::Item(int price , const std::string& manufacturer ) :manufacturer(manufacturer), price(price), id(nextItemID) {
    nextItemID++;
}

Item::~Item() {
    std::cout << "Throwing away an item" << std::endl;
}

int Item::getId() const {
    return id;
}

std::string Item::getManufacturer() const {
    return manufacturer;
}

int Item::getPrice() const {
    return price;
}

void Item::setManufacturer(const std::string& manufacturer) {
    this->manufacturer = manufacturer;
}

void Item::setPrice(int price) {
    this->price = price;
}

bool Item::operator==(const Item& other)const {
    return (id == other.id);
}

bool Item::itemPtrCompare(Item* item1, Item* item2) {
    return item1->id < item2->id;
}


