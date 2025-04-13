#include "Combat_Weapon.hpp"
#include <iomanip>

Combat_Weapon::Combat_Weapon() {}

string Combat_Weapon::get_name() {return name;}

float Combat_Weapon::get_dmg() {return damage;}

string Combat_Weapon::get_type() {return type;}

void Combat_Weapon::display() {
    cout << "== Combat Weapon Description ==\n";
    cout << "Type: " << type << endl;
    cout << "Name: " << name << endl;
    cout << "Damage: " << damage << endl;
    cout << endl;
}