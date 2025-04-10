#pragma once
#include "../Warrior.hpp"

class Mercenary : Warrior {
public:
    Mercenary(bool l = false);

    ~Mercenary() override = default;
};