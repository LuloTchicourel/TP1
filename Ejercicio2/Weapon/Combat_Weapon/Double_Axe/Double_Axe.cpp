#include "Double_Axe.hpp"

Double_Axe::Double_Axe(bool special){
    name = "Double Axe"; weight = 2.4; 
    crit_chance = 0.13; crit_multi = 2.4;
    if(!special){
        damage = 150; enchanted = special;
    }
    else {
        damage = 200; enchanted = special;
    }
}

