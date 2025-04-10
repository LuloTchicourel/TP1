#include "Warlock.hpp"

Warlock::Warlock(bool m){
    name = "Warlock";  intelligence = 73; defence = 0.4;
    if(!m){
        hp = 1280; master = m;
    }
    else {
        hp = 1550; master = m;
    }
}
