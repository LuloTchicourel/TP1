#include "Barbarian.hpp"

Barbarian::Barbarian() {
    name = "Barbarian";
    hp = 100;
}

void Barbarian::set_custom_name(const string& n) {name = n;}