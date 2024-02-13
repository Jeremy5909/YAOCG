//
// Created by Jeremy Eiser Herczeg on 2/8/24.
//

#include "Room.h"

#include <utility>

void Room::AddObject(Object* toAdd) {
    pObjects.push_back(toAdd);
}

Object* Room::FindObjectByName(const std::string& name) {
    for (auto& obj : pObjects) {
        if(obj->getName() == name) {
            return obj;
        }
    }
    return nullptr;
}

const std::vector<Object*> &Room::getObjects() const {
    return pObjects;
}

const std::string &Room::getName() const {
    return pName;
}

Room::Room(std::string pName) : pName(std::move(pName)) {}

Object* Room::operator [](const std::string& name) {
    return FindObjectByName(name);
}
