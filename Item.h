//
// Created by Jeremy Eiser Herczeg on 2/12/24.
//

#ifndef ZOMBIELIFE3_ITEM_H
#define ZOMBIELIFE3_ITEM_H

#include <string>

class Item {
private:
    std::string pName;
public:
    [[nodiscard]] const std::string &getName() const;

public:
    explicit Item(std::string pName);
};


#endif //ZOMBIELIFE3_ITEM_H
