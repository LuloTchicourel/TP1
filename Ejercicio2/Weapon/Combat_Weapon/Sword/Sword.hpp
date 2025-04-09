#pragma once
#include "Combat_Weapon.hpp"

class Sword : Combat_Weapon {
public:
    Sword(bool special = false);

    ~Sword() override = default;
};