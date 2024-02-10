//
// Created by Jeremy Eiser Herczeg on 2/8/24.
//

#ifndef ZOMBIELIFE3_TOGGLEABLE_H
#define ZOMBIELIFE3_TOGGLEABLE_H


#include "Object.h"

class Toggleable : public Object{
private:
    bool toggled;
public:
    explicit Toggleable(const std::string &name);
    void Toggle();
    void Use() override;

};


#endif //ZOMBIELIFE3_TOGGLEABLE_H
