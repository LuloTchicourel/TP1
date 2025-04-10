#include "Gladiator.hpp"

Gladiator::Gladiator(bool l) {
    strength = 76; defence = 0.3;
    lord = l; name = "Gladiator";
    if (!l) hp = 1800;
    else {
        hp = 2300;
        name = "Lord " + name;
    }
}