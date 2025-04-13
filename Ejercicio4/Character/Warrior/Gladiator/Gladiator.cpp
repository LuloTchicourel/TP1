#include "Gladiator.hpp"

Gladiator::Gladiator() {
    name = "Gladiator";
    hp = 100;
}

void Gladiator::set_custom_name(const string& n) {name = n;}