#include "Warrior.hpp"

Warrior::Warrior() {}

void Warrior::attack(Character& enemy, string& weapon_name){
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
    << " with " << weapon->get_name() << ", dealing " << final_damage << " damage.\n";
}

bool Warrior::ram_attack(Character& enemy){
    if (!enemy.is_alive()) {
        cout << "Enemy is already dead..." << endl;
        return false;
    }
    float chance = strength / 100.0f;
    float roll = static_cast<float>(rand()) / RAND_MAX;
    if (roll <= chance){
        float damage = 200 + (strength * 0.4f);
        float final_damage = damage / (1 + enemy.get_defence());
        enemy.receive_damage(final_damage);
        cout << name << " performs a RAM attack on " << enemy.get_name()
             << ", dealing " << final_damage << " damage!" << endl;
        add_xp(final_damage / 3.0f);
        return true;
    }
    cout << name << "'s RAM attack missed!" << endl;
    return false;
}

void Warrior::receive_damage(float dmg) {
    if (!alive){
        cout << "This warrior is already dead..." << endl;
        return;
    }
    hp -= dmg;
    if (hp < 0){
        hp = 0;
        alive = false;
        cout << "Warrior has died." << endl;
    }
}

string Warrior::get_name() {return name;}

bool Warrior::is_alive() {return alive;}

void Warrior::set_custom_name(string n) {name = n;}

float Warrior::get_hp() {return hp;}

float Warrior::get_defence() {return defence;}

string Warrior::get_type() {return type;}

void Warrior::show_weapons(){
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

void Warrior::add_weapon(unique_ptr<Weapon> weapon){
    weapons.push_back(move(weapon));
    cout << name << " acquired a new weapon!" << endl;
}

void Warrior::remove_weapon(string weapon_name){
    for (int i = 0; i < weapons.size(); i++){
        if (weapons[i]->get_name() == weapon_name){
            weapons.erase(weapons.begin() + i);
            cout << name << " removed the weapon \"" << weapon_name << "\" from their inventory." << endl;
            return;
        }
    }
    cout << "Weapon \"" << weapon_name << "\" not found in inventory." << endl;
}

void Warrior::remove_weapon(string weapon_name){
    for (int i = 0; i < weapons.size(); i++){
        if (weapons[i]->get_name() == weapon_name){
            weapons.erase(weapons.begin() + i);
            cout << name << " removed the weapon \"" << weapon_name << "\" from their inventory." << endl;
            return;
        }
    }
    cout << "Weapon \"" << weapon_name << "\" not found in inventory." << endl;
}

Weapon* Warrior::get_weapon_by_name(string& n){
    for (int i = 0; i < weapons.size(); i++){
        if (weapons[i]->get_name() == n){
            return weapons[i].get();
        }
    }
    return nullptr;
}

void Warrior::display(){
    cout << "=== Warrior Status ===" << endl;
    cout << "Name: " << name << endl;
    cout << "HP: " << hp << endl;
    cout << "Level: " << level << endl;
    cout << "Experience: " << experience << "/" << threshold << endl;
    cout << "Defence: " << defence << endl;
    cout << "Strength: " << strength << endl;
    cout << "Alive: " << (alive ? "Yes" : "No") << endl;
    show_weapons();
    cout << endl;
}