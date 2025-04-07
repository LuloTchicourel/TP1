#include "Middle_Manager.hpp"

Middle_Manager::Middle_Manager(string n, string j, int time, float s, float b, Levels lvl)
: Manager(n, j, time, s, b, lvl) {
    if (lvl != Levels::MID)
        throw invalid_argument("Cannot create a Middle Manager with a level other than MID.");
}