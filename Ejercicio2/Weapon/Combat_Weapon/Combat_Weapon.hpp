#pragma once
#include "../Weapon.hpp"

class Combat_Weapon : public Weapon {
protected:
    int threshold = 100;
    string name;
    float weight;
    float damage;
    float crit_chance;
    float crit_multi;
    string type = "Combat_Weapon";
    int level = 1;
    float experience = 0;
    bool enchanted;
public:
    Combat_Weapon();

    string get_name() override;
    void set_custom_name(string n) override;
    float get_weight() override;
    float get_dmg() override;
    string get_type() override;
    int get_level() override;
    void add_xp(float xp) override;
    void display() override;

    ~Combat_Weapon() override = default;
};