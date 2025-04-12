#pragma once
#include "../Warrior.hpp"

class Knight : public Warrior {
public:
    Knight(bool l = false);

    ~Knight() override = default;
};