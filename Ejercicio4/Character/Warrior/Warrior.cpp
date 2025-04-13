#include "Warrior.hpp"

Warrior::Warrior() {}

void Warrior::attack(Character& enemy) {
    if (!enemy.is_alive()) {
        cout << "Enemy is already dead..." << endl;
        return;
    }
    Combat_Weapon* cw = get_weapon();
    if (!cw){
        cout << "No weapons available.\n";
        return;
    }
    float damage = cw->get_dmg();
    enemy.receive_damage(damage);
    cout << name << " attacks " << enemy.get_name()
    << " with " << cw->get_name() << ", dealing "
    << damage << " damage.\n";
    return;
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

float Warrior::get_hp() {return hp;}

string Warrior::get_type() {return type;}

void Warrior::show_weapon(){
    if (!weapon){
        cout << "No weapons available." << endl;
        return;
    }
    cout << "== WEAPON ==" << endl;
    weapon->display();
}

void Warrior::add_weapon(unique_ptr<Weapon> w){
    weapon = std::move(w);
    cout << name << " acquired a new weapon!" << endl;
}

void Warrior::remove_weapon(string weapon_name){
    weapon = nullptr;
    cout << "Weapon \"" << weapon_name << "\" not found in inventory." << endl;
}

void Warrior::display(){
    cout << "=== Warrior Status ===" << endl;
    cout << "Name: " << name << endl;
    cout << "HP: " << hp << endl;
    cout << "Alive: " << (alive ? "Yes" : "No") << endl;
    show_weapon();
    cout << endl;
}