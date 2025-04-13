#pragma once
#include "../Combat_Weapon.hpp"

class Sword : public Combat_Weapon {
public:
    Sword(bool special = false);

    void set_custom_name(const string& n) override;

    ~Sword() override = default;
};