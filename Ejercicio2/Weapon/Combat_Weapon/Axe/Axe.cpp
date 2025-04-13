#include "Axe.hpp"

Axe::Axe(bool special){
    name = "Axe"; weight = 1.5; 
    crit_chance = 0.1; crit_multi = 2.0;
    if(!special){
        damage = 170; enchanted = special;
    }
    else {
        damage = 193; enchanted = special;
    }
}

