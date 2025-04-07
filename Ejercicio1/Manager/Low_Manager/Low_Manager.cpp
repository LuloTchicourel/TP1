#include "Low_Manager.hpp"

Low_Manager::Low_Manager(string n, string j, int time, float s, float b, Levels lvl)
: Manager(n, j, time, s, b, lvl) {
    if (lvl != Levels::LOW)
        throw invalid_argument("Cannot create a Low Manager with a level other than LOW.");
}