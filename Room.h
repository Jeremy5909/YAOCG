//
// Created by Jeremy Eiser Herczeg on 2/8/24.
//

#ifndef ZOMBIELIFE3_ROOM_H
#define ZOMBIELIFE3_ROOM_H

#include <vector>
#include "Object.h"

class Room {
private:
    std::vector<Object> pObjects;
public:
    const std::vector<Object> &getObjects() const;

public:
    void AddObject(const Object& toAdd);
    Object* FindObjectByName(const std::string& name);

    void LookAround();
};


#endif //ZOMBIELIFE3_ROOM_H
