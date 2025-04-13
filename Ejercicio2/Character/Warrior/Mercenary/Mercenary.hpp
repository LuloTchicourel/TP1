#pragma once
#include "../Warrior.hpp"

class Mercenary : public Warrior {
public:
    Mercenary(bool l = false);

    ~Mercenary() override = default;
};