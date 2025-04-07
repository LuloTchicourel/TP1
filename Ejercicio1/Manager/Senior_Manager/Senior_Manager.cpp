#include "Senior_Manager.hpp"

Senior_Manager::Senior_Manager(string n, string j, int time, float s, float b, Levels lvl)
: Manager(n, j, time, s, b, lvl) {
        if (lvl != Levels::HIGH)
        throw invalid_argument("Cannot create a Senior Manager with a level other than HIGH.");
}