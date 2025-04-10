#include "Wizard.hpp"

Wizard::Wizard() {}

void Wizard::attack(Character& enemy, string& weapon_name){
    if (!enemy.is_alive()){
        cout << "Enemy is already dead..." << endl;
        return;
    }
    Weapon* weapon = get_weapon_by_name(weapon_name);
    if (!weapon){
        cout << "Weapon not found.\n";
        return;
    }
    float damage = weapon->get_dmg();
    float final_damage = damage / (1 + enemy.get_defence());
    enemy.receive_damage(final_damage);
    weapon->add_xp(final_damage / 2.5); 
    this->add_xp(final_damage / 3.1);
    cout << name << " attacks " << enemy.get_name()
    << " with " << weapon->get_name() << ", dealing "
    << final_damage << " damage.\n";
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

void Wizard::set_custom_name(string n) {name = n;}

float Wizard::get_hp() {return hp;}

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
    weapons.push_back(move(weapon));
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
        hp += threshold*0.7; 
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