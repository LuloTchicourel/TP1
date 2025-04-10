#include "Barbarian.hpp"

Barbarian::Barbarian(bool l) {
    strength = 81; defence = 0.2;
    lord = l; name = "Barbarian";
    if (!l) hp = 1650;
    else {
        hp = 2100;
        name = "Lord " + name;
    }
}