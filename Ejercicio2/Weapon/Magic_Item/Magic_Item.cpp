#include "Magic_Item.hpp"
#include "../../Character/Character.hpp"
#include "../../Character/Wizard/Wizard.hpp"
#include "../../Character/Warrior/Warrior.hpp"

Magic_Item::Magic_Item(){
    srand(static_cast<unsigned int>(time(0)));
    int roll = rand() % 100;
    if (roll < 50) rarity = Rarity::Common;
    else if (roll < 80) rarity = Rarity::Rare;
    else if (roll < 95) rarity = Rarity::Epic;
    else rarity = Rarity::Legendary;
}

void Magic_Item::apply_to(const string& stat, float percent){
    shared_ptr<Wizard> wiz = dynamic_pointer_cast<Wizard>(player);
    if (wiz){
        wiz->apply_buff(stat, percent);
        return;
    }
    shared_ptr<Warrior> warr = dynamic_pointer_cast<Warrior>(player);
    if (warr){
        warr->apply_buff(stat, percent);
        return;
    }
}

bool Magic_Item::apply_staff_effect(int boost, bool all){
    shared_ptr<Wizard> wiz = dynamic_pointer_cast<Wizard>(player);
    shared_ptr<Warrior> warr = dynamic_pointer_cast<Warrior>(player);
    vector<unique_ptr<Weapon>>* weapon_list = nullptr;
    if (wiz) weapon_list = &wiz->weapons;
    else if (warr) weapon_list = &warr->weapons;
    vector<Magic_Item*> magic_items;

    for (int i = 0; i < weapon_list->size(); i++){
        if ((*weapon_list)[i].get() == this) continue; // para q no se restaure a si mismo
        if ((*weapon_list)[i]->get_type() == "Magic_Item") {
            Magic_Item* m = dynamic_cast<Magic_Item*>((*weapon_list)[i].get());
            if (m) magic_items.push_back(m);
        }
    }
    if (magic_items.empty()){
        cout << "No magic items found to empower.\n";
        return false;
    }

    if (all){
        for (Magic_Item* m : magic_items) m->update_uses(boost);
        cout << "Staff empowered all magic items with +" << boost << " uses.\n";
        return true;
    } 
    else {
        int index = rand() % magic_items.size();
        magic_items[index]->update_uses(boost);
        cout << "Staff empowered 1 magic item with +" << boost << " uses.\n";
        return true;
    }
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

void Magic_Item::update_uses(int change) {uses += change;}

void Magic_Item::set_custom_name(string n) {name = n;}

float Magic_Item::get_effect_strength() {return effect_strength;}

int Magic_Item::get_uses() {return uses;}

void Magic_Item::add_user(shared_ptr<Character> user) {player = user;}

void Magic_Item::display(){
    cout << "== Magic Item Description ==\n"
    << "Name: " << name << endl
    << "Type: " << type << endl
    << "Rarity: " << rarity_to_string() << endl
    << "Effect Strength: " << fixed << setprecision(1) << effect_strength << endl
    << "Weight: " << weight << endl
    << "Uses left: " << uses << endl;
}