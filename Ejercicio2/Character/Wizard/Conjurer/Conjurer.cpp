#include "Conjurer.hpp"

Conjurer::Conjurer(bool m) {
    intelligence = 72; defence = 0.11;
    master = m; name = "Conjurer";
    if (!m) hp = 1300;
    else {
        hp = 1650;
        name = "Master " + name;
    }
}