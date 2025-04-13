#include "Sword.hpp"

Sword::Sword(bool special){
    name = "Sword"; weight = 2.3; 
    crit_chance = 0.08; crit_multi = 3;
    if(!special){
        damage = 165; enchanted = special;
    }
    else {
        damage = 230; enchanted = special;
    }
}

void Sword::set_custom_name(const string& n) {name = n;}
