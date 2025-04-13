#include "Paladin.hpp"

Paladin::Paladin(bool l) {
    strength = 12; defence = 0.8;
    lord = l; name = "Paladin";
    if (!l) {max_hp = 2100; hp = 2100;}
    else {
        max_hp = 2650; hp = 2650;
        name = "Lord " + name;
    }
}

void Paladin::set_custom_name(const string& n) {name = n;}