#pragma once
#include <memory>
#include "../Weapon/Combat_Weapon/Combat_Weapon.hpp"

class Magic_Item;
class Weapon;

class Character {
protected:
    virtual void apply_buff(string stat, float percent) = 0;
public:
    Character() = default;

    virtual void attack(Character& enemy, string& weapon) = 0;
    virtual void receive_damage(float dmg) = 0;
    virtual string get_name() = 0;
    virtual bool is_alive() = 0;
    virtual void set_custom_name(string n) = 0;
    virtual float get_defence() = 0;
    virtual float get_hp() = 0;
    virtual void add_xp(float xp) = 0;
    virtual string get_type() = 0;
    virtual void show_weapons() = 0;
    virtual void add_weapon(unique_ptr<Weapon> weapon) = 0;
    virtual void remove_weapon(string n) = 0;
    virtual Weapon* get_weapon_by_name(string& n) = 0;
    virtual void display() = 0;

    virtual ~Character() = default;
};