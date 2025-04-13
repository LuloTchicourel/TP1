#include "Warlock.hpp"

Warlock::Warlock(bool m) {
    intelligence = 73; defence = 0.4;
    master = m; name = "Warlock";
    if (!m) {max_hp = 1280; hp = 1280;}
    else {
        max_hp = 1550; hp = 1550;
        name = "Master " + name;
    }
}