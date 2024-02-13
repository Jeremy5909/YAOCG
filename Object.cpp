//
// Created by Jeremy Eiser Herczeg on 2/8/24.
//

#include "Object.h"

#include <utility>
#include <iostream>

Object::Object(std::string name) : pName(std::move(name)) {}

const std::string& Object::getName() const {
    return pName;
}

void Object::Use() {
    std::cout << "You cannot use this object." << std::endl;
}

void Object::Inspect() {
    std::cout << "Name: " << pName << std::endl;
}
