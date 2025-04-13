#pragma once
#include "../Combat_Weapon.hpp"

class Axe : public Combat_Weapon {
public:
    Axe();

    void set_custom_name(const string& n) override;

    ~Axe() override = default;
};