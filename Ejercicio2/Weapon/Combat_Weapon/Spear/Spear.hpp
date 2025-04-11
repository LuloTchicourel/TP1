#pragma once
#include "../Combat_Weapon.hpp"

class Spear : public Combat_Weapon {
public:
    Spear(bool special = false);

    ~Spear() override = default;
};