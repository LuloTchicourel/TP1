#include "Wizard.hpp"

Wizard::Wizard() {}

void Wizard::attack(Character& enemy, string& weapon_name) {
    Weapon* weapon = get_weapon_by_name(weapon_name);
    if (!weapon){
        cout << "Weapon not found.\n";
        return;
    }
    float damage = weapon->get_dmg();
    float final_damage = damage / (1 + enemy.get_defence());
    enemy.receive_damage(final_damage);
    weapon->add_xp(final_damage / 2.5); 
    cout << name << " attacks " << enemy.get_name()
    << " with " << weapon->get_name() << ", dealing "
    << final_damage << " damage.\n";
}