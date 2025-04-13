#include "Sword.hpp"

Sword::Sword(){
    name = "Sword";
    damage = 10;
}

void Sword::set_custom_name(const string& n) {name = n;}
