#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "../Weapon/Weapon.hpp"

class Character {
public:
    virtual void attack(Character& enemy) = 0;
    virtual string get_name() = 0;
    virtual float get_hp() = 0;
    virtual string get_type() = 0;
    virtual string show_weapons() = 0;
    virtual void add_weapon(unique_ptr<Weapon> weapon) = 0;

};