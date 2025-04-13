#include "Warlock.hpp"

Warlock::Warlock() {
    name = "Warlock";
    hp = 100;
}

void Warlock::set_custom_name(const string& n) {name = n;}