#include "Spear.hpp"

Spear::Spear(bool special){
    name = "Spear"; weight = 1.1; 
    crit_chance = 0.21; crit_multi = 2.3;
    if(!special){
        damage = 135; enchanted = special;
    }
    else {
        damage = 170; enchanted = special;
    }
}

