#include "Sorcerer.hpp"

Sorcerer::Sorcerer(bool m) {
    intelligence = 91; defence = 0.05;
    master = m; name = "Sorcerer";
    if (!m) {max_hp = 1470; hp = 1470;}
    else {
        max_hp = 1850; hp = 1850;
        name = "Master " + name;
    }
}

void Sorcerer::set_custom_name(const string& n) {name = n;}