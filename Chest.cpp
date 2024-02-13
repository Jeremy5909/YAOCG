//
// Created by Jeremy Eiser Herczeg on 2/12/24.
//

#include "Chest.h"

#include <iostream>
#include <utility>

Chest::Chest(const std::string &name) : Object(name) {}

void Chest::AddTo(Item *item) {
    pInventory.push_back(item);
}

void Chest::operator+(Item *item) {
    AddTo(item);
}

const std::vector<Item *> &Chest::getInventory() const {
    return pInventory;
}

Item *Chest::FindItemByName(std::string name) {
    for (auto& item : pInventory) {
        if(item->getName() == name) {
            return item;
        }
    }
    return nullptr;
}

void Chest::Inspect() {
    Object::Inspect();
    std::cout << "Items: " << std::endl;

    for(auto& item : pInventory) {
        std::cout << "\t -" << item->getName() << std::endl;
    }
}

void Chest::Use() {
    std::cout << "You cannot use this object. You can 'take' though" << std::endl;
}

Item *Chest::operator[](std::string name) {
    return FindItemByName(std::move(name));
}

void Chest::Remove(Item* item) {
    pInventory.erase(std::remove(pInventory.begin(), pInventory.end(), item), pInventory.end());
}
