#pragma once
#include "../Warrior.hpp"

class Gladiator : public Warrior {
public:
    Gladiator(bool l = false);

    ~Gladiator() override = default;
};