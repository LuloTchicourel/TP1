#include "Manager.hpp"

Manager::Manager(string n, string j, int time, float s, float b, Levels lvl) : 
Employee(n, j, time, s), bonus(b), level(lvl) {}

bool Manager::update_bonus(float new_bonus){
    if (new_bonus >= 0){
        bonus = new_bonus;
        cout << "Bonus updated to " << new_bonus << " succesfully." << endl;
        return true;
    }
    cout << "New bonus value is invalid." << endl;
    return false;
}

float Manager::get_bonus() {return bonus;}

bool Manager::set_level(Levels lvl){
    // no se si hacer string para identificar o strings cualquiera
    // hago restringido c el enum class 'levels'
    level = lvl;
}

