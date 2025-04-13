#pragma once
#include "../Combat_Weapon.hpp"

class Sword : public Combat_Weapon {
public:
    Sword();

    void set_custom_name(const string& n) override;

    ~Sword() override = default;
};