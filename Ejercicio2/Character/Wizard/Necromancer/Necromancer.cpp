#include "Necromancer.hpp"

Necromancer::Necromancer(bool m){
    name = "Necromancer";  intelligence = 64; defence = 0.14;
    if(!m){
        hp = 1700; master = m;
    }
    else {
        hp = 2150; master = m;
    }
}
