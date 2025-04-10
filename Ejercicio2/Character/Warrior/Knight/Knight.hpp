#pragma once
#include "../Warrior.hpp"

class Knight : Warrior {
public:
    Knight(bool l = false);

    ~Knight() override = default;
};