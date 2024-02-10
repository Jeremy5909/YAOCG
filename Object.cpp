//
// Created by Jeremy Eiser Herczeg on 2/8/24.
//

#include "Object.h"

#include <utility>
#include <iostream>

Object::Object(std::string name) : name(std::move(name)) {}

const std::string& Object::getName() const {
    return name;
}

void Object::Use() {
    std::cout << "You cannot use this object." << std::endl;
}
