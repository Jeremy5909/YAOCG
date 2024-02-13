//
// Created by Jeremy Eiser Herczeg on 2/8/24.
//

#ifndef ZOMBIELIFE3_OBJECT_H
#define ZOMBIELIFE3_OBJECT_H

#include <string>

class Object {
    std::string pName;
public:
    [[nodiscard]] const std::string &getName() const;
    explicit Object(std::string name);
    virtual void Use();
    virtual void Inspect();
};


#endif //ZOMBIELIFE3_OBJECT_H
