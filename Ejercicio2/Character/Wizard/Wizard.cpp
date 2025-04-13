#include "Wizard.hpp"

Wizard::Wizard() {}

void Wizard::apply_buff(string stat, float percent) {
    if (!alive){
        cout << name << " is dead and cannot receive buffs." << endl;
        return;
    }
    if (stat == "hp"){
        hp = hp + percent;
        if (hp > max_hp) hp = max_hp;
        cout << name << " received a HP buff of " << percent << ", now at " << hp << "/" << max_hp << " HP.\n";
    }
    else if (stat == "def"){
        float increase = defence * percent;
        defence += increase;
        cout << name << " increased defence by " << increase << ", now at " << defence << ".\n";
    }
    else if (stat == "int"){
        float increase = intelligence * percent;
        intelligence += increase;
        cout << name << " increased intelligence by " << increase << ", now at " << intelligence << ".\n";
    }
    else {
        cout << "Unknown stat: " << stat << ". No buff applied.\n";
    }
}

void Wizard::attack(Character& enemy, string& weapon_name) {
    if (!enemy.is_alive()) {
        cout << "Enemy is already dead..." << endl;
        return;
    }
    Weapon* base_weapon = get_weapon_by_name(weapon_name);
    if (!base_weapon){
        cout << "Weapon not found.\n";
        return;
    }
    if (base_weapon->get_type() == "Combat_Weapon"){
        Combat_Weapon* cw = dynamic_cast<Combat_Weapon*>(base_weapon);
        if (cw){
            float damage = cw->get_dmg();
            float final_damage = damage / (1 + enemy.get_defence());
            enemy.receive_damage(final_damage);
            cw->add_xp(final_damage / 2.5);
            this->add_xp(final_damage / 3.1);
            cout << name << " attacks " << enemy.get_name()
            << " with " << cw->get_name() << ", dealing "
            << final_damage << " damage.\n";
            return;
        }
    }
    if (base_weapon->get_type() == "Magic_Item"){
        Magic_Item* mi = dynamic_cast<Magic_Item*>(base_weapon);
        if (mi) {mi->use(); return;}
    }
}

bool Wizard::cast_spell(Character& enemy){
    if (!enemy.is_alive()){
        cout << "Enemy is already dead..." << endl;
        return false;
    }
    float chance = intelligence / 100.0f;
    float roll = static_cast<float>(rand()) / RAND_MAX;
    if (roll <= chance){
        float damage = 150 + (intelligence * 0.5f);
        float final_damage = damage / (1 + enemy.get_defence());
        enemy.receive_damage(final_damage);
        cout << name << " casts a spell on " << enemy.get_name()
             << ", dealing " << final_damage << " damage!\n";
        return true;
    } 
    else {
        cout << name << "'s spell failed!\n";
        return false;
    }
}

void Wizard::receive_damage(float dmg){
    if (!alive){
        cout << "This wizard is already dead..." << endl;
    }
    hp -= dmg;
    if (hp < 0){
        hp = 0;
        alive = false;
        cout << "Wizard has died." << endl;
    }
}

string Wizard::get_name() {return name;}

bool Wizard::is_alive() {return alive;}

float Wizard::get_hp() {return hp;}

float Wizard::get_defence() {return defence;}

string Wizard::get_type() {return type;}

void Wizard::show_weapons() {
    int size = weapons.size();
    if (size == 0){
        cout << "No weapons available." << endl;
        return;
    }
    cout << "== WEAPONS ==" << endl;
    for (int i = 0; i < size; i++){
        if (i == size - 1) cout << weapons[i]->get_name() << ".";
        else cout << weapons[i]->get_name() << ", ";
    }
}

void Wizard::add_weapon(unique_ptr<Weapon> weapon) {
    weapons.push_back(std::move(weapon));
    cout << name << " acquired a new weapon!" << endl;
}

void Wizard::remove_weapon(string weapon_name) {
    for (int i = 0; i < weapons.size(); i++) {
        if (weapons[i]->get_name() == weapon_name) {
            weapons.erase(weapons.begin() + i);
            cout << name << " removed the weapon \"" << weapon_name << "\" from their inventory." << endl;
            return;
        }
    }
    cout << "Weapon \"" << weapon_name << "\" not found in inventory." << endl;
}

void Wizard::add_xp(float xp) {
    experience += xp;
    while (experience >= threshold) {
        level++;
        max_hp += threshold*0.7; 
        hp += hp*0.25;
        experience = (int)experience % 100;
        threshold += 15;
        cout << name << " has leveled up! Now level " << level << "!" << endl;
    }
}

Weapon* Wizard::get_weapon_by_name(string& n) {
    for (int i = 0; i < weapons.size(); i++) {
        if (weapons[i]->get_name() == n) {
            return weapons[i].get();
        }
    }
    return nullptr;
}

void Wizard::display() {
    cout << "=== Wizard Status ===" << endl;
    cout << "Name: " << name << endl;
    cout << "HP: " << hp << endl;
    cout << "Level: " << level << endl;
    cout << "Experience: " << experience << "/" << threshold << endl;
    cout << "Defence: " << defence << endl;
    cout << "Intelligence: " << intelligence << endl;
    cout << "Alive: " << (alive ? "Yes" : "No") << endl;
    show_weapons();
    cout << endl;
}