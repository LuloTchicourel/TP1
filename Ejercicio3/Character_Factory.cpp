#include "Character_Factory.hpp"
#include "Character/Wizard/Sorcerer/Sorcerer.hpp"
#include "Character/Wizard/Warlock/Warlock.hpp"
#include "Character/Wizard/Conjurer/Conjurer.hpp"
#include "Character/Wizard/Necromancer/Necromancer.hpp"

#include "Character/Warrior/Barbarian/Barbarian.hpp"
#include "Character/Warrior/Knight/Knight.hpp"
#include "Character/Warrior/Mercenary/Mercenary.hpp"
#include "Character/Warrior/Paladin/Paladin.hpp"
#include "Character/Warrior/Gladiator/Gladiator.hpp"

#include "Weapon/Magic_Item/Potion/Potion.hpp"
#include "Weapon/Magic_Item/Spellbook/Spellbook.hpp"
#include "Weapon/Magic_Item/Staff/Staff.hpp"
#include "Weapon/Magic_Item/Amulet/Amulet.hpp"

#include "Weapon/Combat_Weapon/Axe/Axe.hpp"
#include "Weapon/Combat_Weapon/Sword/Sword.hpp"
#include "Weapon/Combat_Weapon/Spear/Spear.hpp"
#include "Weapon/Combat_Weapon/Double_Axe/Double_Axe.hpp"


#include <iostream>
#include <algorithm>


shared_ptr<Character> Character_Factory::create_character_by_type(const string& type, int weapon_count){
    shared_ptr<Character> character;

    if (type == "sorcerer") character = make_shared<Sorcerer>(false);
    else if (type == "warlock") character = make_shared<Warlock>(false);
    else if (type == "conjurer") character = make_shared<Conjurer>(false);
    else if (type == "necromancer") character = make_shared<Necromancer>(false);
    else if (type == "barbarian") character = make_shared<Barbarian>(false);
    else if (type == "knight") character = make_shared<Knight>(false);
    else if (type == "mercenary") character = make_shared<Mercenary>(false);
    else if (type == "paladin") character = make_shared<Paladin>(false);
    else if (type == "gladiator") character = make_shared<Gladiator>(false);
    else return nullptr;

    for (int i = 0; i < weapon_count; ++i){
        unique_ptr<Weapon> weapon = create_random_weapon();

        Weapon* raw = weapon.get();
        Magic_Item* magic = dynamic_cast<Magic_Item*>(raw);
        if (magic != nullptr){
            magic->add_user(character);
        }
        character->add_weapon(std::move(weapon));
    }
    return character;
}

shared_ptr<Character> Character_Factory::create_armed_character(const string& category, int weapon_count){
    vector<string> types;

    if (category == "wizard"){
        types = { "sorcerer", "warlock", "conjurer", "necromancer" };
    } 
    else if (category == "warrior"){
        types = { "barbarian", "knight", "mercenary", "paladin", "gladiator" };
    } 
    else return nullptr;

    int random_index = rand() % types.size();
    string selected = types[random_index];

    return create_character_by_type(selected, weapon_count);
}

unique_ptr<Weapon> Character_Factory::create_random_weapon(){
    int category = rand() % 2;
    int type = rand() % 4;

    if (category == 0){
        if (type == 0) return make_unique<Potion>();
        if (type == 1) return make_unique<Spellbook>();
        if (type == 2) return make_unique<Staff>();
        if (type == 3) return make_unique<Amulet>();
        return make_unique<Amulet>();
    } 
    else {
        if (type == 0) return make_unique<Axe>(false);
        if (type == 1) return make_unique<Sword>(false);
        if (type == 2) return make_unique<Spear>(false);
        if (type == 3) return make_unique<Double_Axe>(false);
        return make_unique<Axe>(true);
    }
}