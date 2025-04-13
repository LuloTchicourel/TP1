#pragma once
#include <memory>
#include "../Weapon/Combat_Weapon/Combat_Weapon.hpp"

class Magic_Item;
class Combat_Weapon;

class Character {
public:
    Character() = default;

    virtual void attack(Character& enemy) = 0;
    virtual void receive_damage(float dmg) = 0;
    virtual string get_name() = 0;
    virtual bool is_alive() = 0;
    virtual float get_hp() = 0;
    virtual string get_type() = 0;
    virtual void show_weapon() = 0;
    virtual void add_weapon(unique_ptr<Combat_Weapon> weapon) = 0;
    virtual void remove_weapon(string n) = 0;
    virtual Combat_Weapon* get_weapon() = 0;
    virtual void display() = 0;

    virtual ~Character() = default;
};