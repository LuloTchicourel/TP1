#include "Paladin.hpp"

Paladin::Paladin(bool l) {
    strength = 12; defence = 0.8;
    lord = l; name = "Paladin";
    if (!l) hp = 2100;
    else {
        hp = 2650;
        name = "Lord " + name;
    }
}