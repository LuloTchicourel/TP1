#include "Character_Factory.hpp"

#include "../Character/Wizard/Sorcerer/Sorcerer.hpp"
#include "../Character/Wizard/Warlock/Warlock.hpp"
#include "../Character/Wizard/Conjurer/Conjurer.hpp"
#include "../Character/Wizard/Necromancer/Necromancer.hpp"

#include "../Character/Warrior/Barbarian/Barbarian.hpp"
#include "../Character/Warrior/Knight/Knight.hpp"
#include "../Character/Warrior/Mercenary/Mercenary.hpp"
#include "../Character/Warrior/Paladin/Paladin.hpp"
#include "../Character/Warrior/Gladiator/Gladiator.hpp"

#include "../Weapon/Combat_Weapon/Axe/Axe.hpp"
#include "../Weapon/Combat_Weapon/Sword/Sword.hpp"
#include "../Weapon/Combat_Weapon/Spear/Spear.hpp"
#include "../Weapon/Combat_Weapon/Double_Axe/Double_Axe.hpp"


unique_ptr<Character> Character_Factory::create_character_by_type(const string& type, const string& weapon) {
    unique_ptr<Character> character;
    unique_ptr<Combat_Weapon> w;

    if (type == "Sorcerer") character = make_unique<Sorcerer>();
    else if (type == "Warlock") character = make_unique<Warlock>();
    else if (type == "Conjurer") character = make_unique<Conjurer>();
    else if (type == "Necromancer") character = make_unique<Necromancer>();
    else if (type == "Barbarian") character = make_unique<Barbarian>();
    else if (type == "Knight") character = make_unique<Knight>();
    else if (type == "Mercenary") character = make_unique<Mercenary>();
    else if (type == "Paladin") character = make_unique<Paladin>();
    else if (type == "Gladiator") character = make_unique<Gladiator>();

    if (!character) return nullptr;

    if(!weapon.empty()){
        if (weapon == "Axe") w = make_unique<Axe>();
        else if (weapon == "Sword") w = make_unique<Sword>();
        else if (weapon == "Spear") w = make_unique<Spear>();
        else if (weapon == "Double_Axe") w = make_unique<Double_Axe>();
    }

    if (w) character->add_weapon(std::move(w));
    return std::move(character);
}

unique_ptr<Character> Character_Factory::create_random_character() {
    int type = rand() % 8;

    switch (type) {
        case 0: return make_unique<Barbarian>();
        case 1: return make_unique<Knight>();
        case 2: return make_unique<Mercenary>();
        case 3: return make_unique<Paladin>();
        case 4: return make_unique<Gladiator>();
        case 5: return make_unique<Sorcerer>();
        case 6: return make_unique<Warlock>();
        case 7: return make_unique<Conjurer>();
    }
    return nullptr; 
}

unique_ptr<Weapon> Character_Factory::create_random_weapon() {
    int type = rand() % 4;

    switch (type) {
        case 0: return make_unique<Axe>(false);
        case 1: return make_unique<Sword>(false);
        case 2: return make_unique<Spear>(false);
        case 3: return make_unique<Double_Axe>(false);
    }
    return nullptr; 
}
