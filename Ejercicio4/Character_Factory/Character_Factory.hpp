#pragma once
#include <memory>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Weapon;
class Character;

class Character_Factory {
public:
    static unique_ptr<Weapon> create_random_weapon();    
    static unique_ptr<Character> create_random_character();

    static unique_ptr<Character> create_character_by_type(const string& type, const string& weapon = "");
};