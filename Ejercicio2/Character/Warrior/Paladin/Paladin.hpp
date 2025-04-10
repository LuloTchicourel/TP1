#pragma once
#include "../Warrior.hpp"

class Paladin : Warrior {
public:
    Paladin(bool l = false);

    ~Paladin() override = default;
};