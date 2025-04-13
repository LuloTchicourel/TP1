#include "Necromancer.hpp"

Necromancer::Necromancer() {
    name = "Necromancer";
    hp = 100;
}

void Necromancer::set_custom_name(const string& n) {name = n;}