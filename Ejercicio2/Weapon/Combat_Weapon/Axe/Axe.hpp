#pragma once
#include "../Combat_Weapon.hpp"

class Axe : public Combat_Weapon {
public:
    Axe(bool special = false);

    ~Axe() override = default;
};