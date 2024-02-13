//
// Created by Jeremy Eiser Herczeg on 2/12/24.
//

#ifndef ZOMBIELIFE3_CHEST_H
#define ZOMBIELIFE3_CHEST_H


#include "Object.h"
#include "Item.h"

#include <vector>
#include <string>

class Chest : public Object {
private:
    std::vector<Item*> pInventory;
public:
    explicit Chest(const std::string &name);

    void Use() override;
    void Inspect() override;

    void AddTo(Item* item);
    void operator +(Item* item);

    Item* FindItemByName(std::string name);
    Item* operator [](std::string name);

    void Remove(Item* item);

    [[nodiscard]] const std::vector<Item *> &getInventory() const;
};


#endif //ZOMBIELIFE3_CHEST_H
