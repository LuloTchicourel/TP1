#include "Knight.hpp"

Knight::Knight() {
    name = "Knight";
    hp = 100;
}

void Knight::set_custom_name(const string& n) {name = n;}