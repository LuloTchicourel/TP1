#pragma once
#include "Manager.hpp"

class Team_Leader : public Manager {
public:
    Team_Leader(string n, string j, int time, float s, float b, Levels lvl);
};