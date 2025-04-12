#pragma once
#include "../Combat_Weapon.hpp"

class Double_Axe : public Combat_Weapon {
public:
    Double_Axe(bool special = false);

    ~Double_Axe() override = default;
};