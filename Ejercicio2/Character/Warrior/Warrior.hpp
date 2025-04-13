#pragma once
#include "../Character.hpp"
#include "../../Weapon/Magic_Item/Magic_Item.hpp"
#include "../../Weapon/Combat_Weapon/Combat_Weapon.hpp"

class Warrior : public Character {
protected:
    bool alive = true;
    bool lord;
    int threshold = 100;
    string name;
    float hp;
    float max_hp;
    float strength;
    float defence;
    int level = 1;
    float experience = 0;
    string type = "Warrior";
    vector<unique_ptr<Weapon>> weapons;    

    void apply_buff(string stat, float percent) override;
public:
    Warrior();

    void attack(Character& enemy, string& weapon) override;
    bool ram_attack(Character& enemy);
    void receive_damage(float dmg) override;

    string get_name() override;
    bool is_alive() override;
    virtual void set_custom_name(const string& n) = 0;
    float get_defence() override;
    float get_hp() override;
    string get_type() override;
    void show_weapons() override;
    void add_weapon(unique_ptr<Weapon> weapon) override;
    void remove_weapon(string n) override;
    void add_xp(float xp) override;
    Weapon* get_weapon_by_name(string& n) override;
    void display() override;

    ~Warrior() override = default;

    friend class Magic_Item;
};