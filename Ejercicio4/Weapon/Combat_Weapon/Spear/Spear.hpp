#pragma once
#include "../Combat_Weapon.hpp"

class Spear : public Combat_Weapon {
public:
    Spear();

    void set_custom_name(const string& n) override;

    ~Spear() override = default;
};