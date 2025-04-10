#include "Warlock.hpp"

Warlock::Warlock(bool m) {
    intelligence = 73; defence = 0.4;
    master = m; name = "Warlock";
    if (!m) hp = 1280;
    else {
        hp = 1550;
        name = "Master " + name;
    }
}