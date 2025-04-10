#include "Mercenary.hpp"

Mercenary::Mercenary(bool l) {
    strength = 90; defence = 0.1;
    lord = l; name = "Mercenary";
    if (!l) hp = 1450;
    else {
        hp = 1800;
        name = "Lord " + name;
    }
}