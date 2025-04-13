#include "Gladiator.hpp"

Gladiator::Gladiator(bool l) {
    strength = 76; defence = 0.3;
    lord = l; name = "Gladiator";
    if (!l) {max_hp = 1800; hp = 1800;}
    else {
        max_hp = 2300; hp = 2300;
        name = "Lord " + name;
    }
}

void Gladiator::set_custom_name(const string& n) {name = n;}