#pragma once
#include "../Warrior.hpp"

class Gladiator : Warrior {
public:
    Gladiator(bool l = false);

    ~Gladiator() override = default;
};