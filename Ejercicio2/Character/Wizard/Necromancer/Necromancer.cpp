#include "Necromancer.hpp"

Necromancer::Necromancer(bool m) {
    intelligence = 64; defence = 0.14;
    master = m; name = "Necromancer";
    if (!m) hp = 1700;
    else {
        hp = 2150;
        name = "Master " + name;
    }
}