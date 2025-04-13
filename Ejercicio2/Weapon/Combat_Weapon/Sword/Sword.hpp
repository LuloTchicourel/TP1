#pragma once
#include "../Combat_Weapon.hpp"

class Sword : public Combat_Weapon {
public:
    Sword(bool special = false);

    ~Sword() override = default;
};