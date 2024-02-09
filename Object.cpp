//
// Created by Jeremy Eiser Herczeg on 2/8/24.
//

#include "Object.h"

#include <utility>

Object::Object(std::string name) : name(std::move(name)) {}

const std::string& Object::getName() const {
    return name;
}
