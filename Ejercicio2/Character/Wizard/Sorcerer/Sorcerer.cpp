#include "Sorcerer.hpp"

Sorcerer::Sorcerer(bool m){
    name = "Sorcerer";  intelligence = 91; defence = 0.05;
    if(!m){
        hp = 1470; master = m;
    }
    else {
        hp = 1850; master = m;
    }
}
