//
// Created by Jeremy Eiser Herczeg on 2/8/24.
//

#include <iostream>
#include "Toggleable.h"

void Toggleable::Toggle() {
    toggled = !toggled;
}

Toggleable::Toggleable(const std::string &name) : Object(name) {
    toggled = false;
}

void Toggleable::Use() {
    Toggle();
    std::cout << getName() << " now ";
    toggled ? std::cout << "on" : std::cout << "off";
    std::cout << std::endl;  // Add a newline to separate the output
}

void Toggleable::Inspect() {
    Object::Inspect();
    std::cout << "Status: " << (toggled ? "on" : "off") << std::endl;
};