#include "Barbarian.hpp"

Barbarian::Barbarian(bool l) {
    strength = 81; defence = 0.2;
    lord = l; name = "Barbarian";
    if (!l) {max_hp = 1650; hp = 1650;}
    else {
        max_hp = 2100; hp = 2100;
        name = "Lord " + name;
    }
}