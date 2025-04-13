#include "Wizard.hpp"

Wizard::Wizard() {}


void Wizard::attack(Character& enemy) {
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

void Wizard::receive_damage(float dmg) {
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

string Wizard::get_name() {return name;}

bool Wizard::is_alive() {return alive;}

float Wizard::get_hp() {return hp;}

string Wizard::get_type() {return type;}

void Wizard::show_weapon(){
    if (!weapon){
        cout << "No weapons available." << endl;
        return;
    }
    weapon->display();
}

void Wizard::add_weapon(unique_ptr<Combat_Weapon> w){
    weapon = std::move(w);
    cout << name << " acquired a new weapon!" << endl;
}

void Wizard::remove_weapon(string weapon_name){
    weapon = nullptr;
    cout << "Weapon has been deleted from the inventory." << endl;
}

Combat_Weapon* Wizard::get_weapon(){
    if (!weapon) return nullptr;
    return weapon.get();
}

void Wizard::display(){
    cout << "=== Wizard Status ===" << endl;
    cout << "Name: " << name << endl;
    cout << "HP: " << hp << endl;
    cout << "Alive: " << (alive ? "Yes" : "No") << endl;
    show_weapon();
    cout << endl;
}