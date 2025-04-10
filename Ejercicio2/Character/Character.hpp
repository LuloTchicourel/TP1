#include <memory>
#include "../Weapon/Weapon.hpp"

class Character {
public:
    virtual void attack(Character& enemy, string& weapon) = 0;
    virtual void receive_damage(float dmg) = 0;
    virtual string get_name() = 0;
    virtual void set_custom_name(string n) = 0;
    virtual float get_defence() = 0;
    virtual float get_hp() = 0;
    virtual string get_type() = 0;
    virtual string show_weapons() = 0;
    virtual void add_weapon(unique_ptr<Weapon> weapon) = 0;
    virtual void remove_weapon(string t) = 0;
    virtual Weapon* get_weapon_by_name(string& n);
    virtual void display() = 0;

    virtual ~Character() = default;
};