#include "Paladin.hpp"

Paladin::Paladin() {
    name = "Paladin";
    hp = 100;
}

void Paladin::set_custom_name(const string& n) {name = n;}