#pragma once
#include "Employee.hpp"

enum class Levels {HIGH, MID, LOW, TL};

class Manager : public Employee {
private:
    float bonus;
    Levels level;
public:
    Manager(string n, string j, int time, float s, float b, Levels lvl);

    bool update_bonus(float new_bonus);
    float get_bonus();
    bool set_level(Levels lvl);

    ~Manager() override;
};