//
// Created by Jeremy Eiser Herczeg on 2/12/24.
//

#include "Item.h"

#include <utility>

Item::Item(std::string pName) : pName(std::move(pName)) {}

const std::string &Item::getName() const {
    return pName;
}
