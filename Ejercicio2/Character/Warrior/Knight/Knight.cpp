#include "Knight.hpp"

Knight::Knight(bool l) {
    strength = 58; defence = 0.39;
    lord = l; name = "Knight";
    if (!l) {max_hp = 2000; hp = 2000;}
    else {
        max_hp = 2500; hp = 2500;
        name = "Lord " + name;
    }
}

void Knight::set_custom_name(const string& n) {name = n;}