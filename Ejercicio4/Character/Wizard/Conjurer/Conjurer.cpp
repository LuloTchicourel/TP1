#include "Conjurer.hpp"

Conjurer::Conjurer() {
    name = "Conjurer";
    hp = 100;
}

void Conjurer::set_custom_name(const string& n) {name = n;}