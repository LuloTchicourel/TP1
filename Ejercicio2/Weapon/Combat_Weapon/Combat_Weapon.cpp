#pragma once
#include "Combat_Weapon.hpp"
#include <iomanip>

Combat_Weapon::Combat_Weapon() {}

string Combat_Weapon::get_name() {return name;}

void Combat_Weapon::set_custom_name(string n) {name = n;}

float Combat_Weapon::get_weight() {return weight;}

float Combat_Weapon::get_dmg() {return damage;}

string Combat_Weapon::get_type() {return type;}

int Combat_Weapon::get_level() {return level;}

void Combat_Weapon::add_xp(float xp){
    experience += xp;
    while (experience >= threshold){
        level++;
        damage *= 1.1f;
        experience = (int)experience % 100;
        threshold += 10;
        cout << name << " has leveled up! Now level " << level << "!" << endl;
    }
}

void Combat_Weapon::display() {
    cout << "== Weapon Description ==\n";
    cout << "Type: " << type << endl;
    if (enchanted) cout << "**ENCHANTED**" << endl;
    cout << "Name: " << name << endl;
    cout << "Weight: " << weight << endl;
    cout << "Damage: " << damage << endl;
    cout << "Level: " << level << endl;
    cout << "Experience: " << experience << "/" << threshold << endl;
    cout << endl;
}