#pragma once
#include "../Weapon.hpp"

class Combat_Weapon : public Weapon {
protected:
    string name;
    float damage;
    string type = "Combat_Weapon";
public:
    Combat_Weapon();

    string get_name() override;
    virtual void set_custom_name(const string& n) = 0;
    string get_type() override;
    void display() override;
    float get_dmg();

    ~Combat_Weapon() override = default;
};