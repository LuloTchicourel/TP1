#include "Team_Leader.hpp"

Team_Leader::Team_Leader(string n, string j, int time, float s, float b, Levels lvl)
: Manager(n, j, time, s, b, lvl) {
    if (lvl != Levels::TL)
        throw invalid_argument("Cannot create a Team Leader with a level other than TL.");
}