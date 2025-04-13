#include "Mercenary.hpp"

Mercenary::Mercenary() {
    name = "Mercenary";
    hp = 100;
}

void Mercenary::set_custom_name(const string& n) {name = n;}