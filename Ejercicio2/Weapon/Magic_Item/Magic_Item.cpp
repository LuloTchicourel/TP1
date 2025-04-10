#include "Magic_Item.hpp"

Magic_Item::Magic_Item(){
    srand(static_cast<unsigned int>(time(0)));
    int roll = rand() % 100;
    if (roll < 50) rarity = Rarity::Common;
    else if (roll < 80) rarity = Rarity::Rare;
    else if (roll < 95) rarity = Rarity::Epic;
    else rarity = Rarity::Legendary;
}

string Magic_Item::get_name() {return name;}

float Magic_Item::get_weight() {return weight;}

string Magic_Item::get_type() {return type;}

string Magic_Item::rarity_to_string() const {
    switch (rarity) {
        case Rarity::Common: return "Common";
        case Rarity::Rare: return "Rare";
        case Rarity::Epic: return "Epic";
        case Rarity::Legendary: return "Legendary";
        default: return "Unknown";
    }
}

float Magic_Item::get_effect_strength() {return effect_strength;}

int Magic_Item::get_uses() {return uses;}

void Magic_Item::display(){
    cout << "== Magic Item Description ==\n"
         << "Name: " << name << endl
         << "Type: " << type << endl
         << "Rarity: " << rarity_to_string() << endl
         << "Effect Strength: " << fixed << setprecision(1) << effect_strength << endl
         << "Weight: " << weight << endl
         << "Uses left: " << uses << endl;
}