#include "Sorcerer.hpp"

Sorcerer::Sorcerer(bool m) {
    intelligence = 91; defence = 0.05;
    master = m; name = "Sorcerer";
    if (!m) hp = 1470;
    else {
        hp = 1850;
        name = "Master " + name;
    }
}