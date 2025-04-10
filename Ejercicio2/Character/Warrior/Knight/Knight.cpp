#include "Knight.hpp"

Knight::Knight(bool l) {
    strength = 58; defence = 0.39;
    lord = l; name = "Knight";
    if (!l) hp = 2000;
    else {
        hp = 2500;
        name = "Lord " + name;
    }
}