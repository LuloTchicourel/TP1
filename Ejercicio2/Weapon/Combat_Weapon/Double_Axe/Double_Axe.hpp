#pragma once
#include "../Combat_Weapon.hpp"

class Double_Axe : public Combat_Weapon {
public:
    Double_Axe(bool special = false);

    void set_custom_name(const string& n) override;

    ~Double_Axe() override = default;
};