//
// Created by Jeremy Eiser Herczeg on 2/8/24.
//

#include "Room.h"
#include <iostream>

void Room::AddObject(const Object& toAdd) {
    objects.push_back(toAdd);
}

Object* Room::FindObjectByName(const std::string& name) {
    for (auto& obj : objects) {
        if(obj.getName() == name) {
            return &obj;
        }
    }
    return nullptr;
}

void Room::LookAround() {
    std::cout << "You are in " << std::endl;
    std::cout << "Objects in the room: " << std::endl;

    for (const auto& obj : objects) {
        std::cout << "- " << obj.getName() << std::endl;
    }
}