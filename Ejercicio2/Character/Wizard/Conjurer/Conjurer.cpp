#include "Conjurer.hpp"

Conjurer::Conjurer(bool m) {
    intelligence = 72; defence = 0.11;
    master = m; name = "Conjurer";
    if (!m) {max_hp = 1300; hp = 1300;}
    else {
        max_hp = 1650; hp = 1650; 
        name = "Master " + name;
    }
}