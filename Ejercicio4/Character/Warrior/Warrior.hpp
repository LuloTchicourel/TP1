#pragma once
#include "../Character.hpp"
#include "../../Weapon/Combat_Weapon/Combat_Weapon.hpp"

class Warrior : public Character {
protected:
    bool alive = true;
    string name;
    float hp;
    string type = "Warrior";
    unique_ptr<Combat_Weapon> weapon;    
public:
    Warrior();

    void attack(Character& enemy) override;
    void receive_damage(float dmg) override;

    string get_name() override;
    bool is_alive() override;
    virtual void set_custom_name(const string& n) = 0;
    float get_hp() override;
    string get_type() override;
    void show_weapon() override;
    void add_weapon(unique_ptr<Combat_Weapon> weapon) override;
    void remove_weapon(string n) override;
    Combat_Weapon* get_weapon() override;
    void display() override;

    ~Warrior() override = default;
};