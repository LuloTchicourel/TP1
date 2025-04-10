#pragma once
#include "../Warrior.hpp"

class Barbarian : Warrior {
public:
    Barbarian(bool l = false);

    ~Barbarian() override = default;
};