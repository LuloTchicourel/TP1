#pragma once
#include <memory>
#include <cstdlib>
#include <ctime>
#include "../Character/Wizard/Sorcerer/Sorcerer.hpp"
#include "../Character/Warrior/Barbarian/Barbarian.hpp"
#include "../Weapon/Combat_Weapon/Spear/Spear.hpp"
#include "../Weapon/Magic_Item/Potion/Potion.hpp"

using namespace std;

class Character_Factory {
public:
    static unique_ptr<Weapon> create_random_weapon();
    static shared_ptr<Character> create_character_by_type(const string& type, int weapon_count);
    static shared_ptr<Character> create_armed_character(const string& category, int weapon_count);
};