#pragma once
#include "../Warrior.hpp"

class Paladin : public Warrior {
public:
    Paladin(bool l = false);

    ~Paladin() override = default;
};