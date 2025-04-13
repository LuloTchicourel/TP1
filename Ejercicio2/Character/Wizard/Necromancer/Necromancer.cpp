#include "Necromancer.hpp"

Necromancer::Necromancer(bool m) {
    intelligence = 64; defence = 0.14;
    master = m; name = "Necromancer";
    if (!m) {max_hp = 1700; hp = 1700;}
    else {
        max_hp = 2150; hp = 2150; 
        name = "Master " + name;
    }
}

void Necromancer::set_custom_name(const string& n) {name = n;}