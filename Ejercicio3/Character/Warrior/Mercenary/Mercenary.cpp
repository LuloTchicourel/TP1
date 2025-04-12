#include "Mercenary.hpp"

Mercenary::Mercenary(bool l) {
    strength = 90; defence = 0.1;
    lord = l; name = "Mercenary";
    if (!l) {max_hp = 1450; hp = 1450;}
    else {
        max_hp = 1800; hp = 1800;
        name = "Lord " + name;
    }
}