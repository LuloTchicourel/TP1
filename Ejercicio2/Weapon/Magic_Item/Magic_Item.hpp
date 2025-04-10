#pragma once
#include "../Weapon.hpp"
#include <cstdlib>  
#include <ctime>   
#include <iomanip>

using namespace std;

enum class Rarity { Common, Rare, Epic, Legendary };

class Magic_Item : public Weapon {
protected:
    string name;
    Rarity rarity;
    float effect_strength;
    float weight;
    string type;
    int uses;

    string rarity_to_string() const;
public:
    Magic_Item();

    string get_name() override;
    float get_weight() override;
    string get_type() override;
    void display() override;
    float get_effect_strength();
    int get_uses();
    virtual void use() = 0;

    ~Magic_Item() override = default;
};