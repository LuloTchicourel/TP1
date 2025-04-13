#pragma once
#include "../Weapon.hpp"
#include <memory>
#include <iomanip>

using namespace std;

class Character;

enum class Rarity { Common, Rare, Epic, Legendary };

class Magic_Item : public Weapon {
protected:
    string name;
    Rarity rarity;
    float effect_strength;
    float weight;
    string type = "Magic_Item";
    int uses;
    shared_ptr<Character> player;

    string rarity_to_string() const;
    void update_uses(int change); 
    void apply_to(const string& stat, float percent);
    bool apply_staff_effect(int boost, bool all);
public:
    Magic_Item();

    string get_name() override;
    float get_weight() override;
    virtual void set_custom_name(const string& n) = 0;
    string get_type() override;
    void display() override;
    void add_user(shared_ptr<Character> user);
    float get_effect_strength();
    int get_uses();
    virtual void use() = 0;

    ~Magic_Item() override = default;
};