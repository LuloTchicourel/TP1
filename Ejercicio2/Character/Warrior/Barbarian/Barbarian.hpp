#pragma once
#include "../Warrior.hpp"

class Barbarian : public Warrior {
public:
    Barbarian(bool l = false);

    ~Barbarian() override = default;
};