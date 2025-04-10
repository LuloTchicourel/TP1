#include "Conjurer.hpp"

Conjurer::Conjurer(bool m){
    name = "Conjurer"; intelligence = 72; defence = 0.11;
    if(!m){
        hp = 1300; master = m;
    }
    else {
        hp = 1650; master = m;
    }
}
