#include "Club.hpp"

Club::Club(bool special){
    name = "Club"; weight = 2.6; 
    crit_chance = 0.24; crit_multi = 1.8;
    if(!special){
        damage = 90; enchanted = special;
    }
    else {
        damage = 140; enchanted = special;
    }
}

void Club::set_custom_name(const string& n) {name = n;}
