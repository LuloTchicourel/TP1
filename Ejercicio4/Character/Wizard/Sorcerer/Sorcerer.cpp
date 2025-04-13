#include "Sorcerer.hpp"

Sorcerer::Sorcerer() {
    name = "Sorcerer";
    hp = 100;
}

void Sorcerer::set_custom_name(const string& n) {name = n;}