#include <iostream>
#include <memory>
#include "Character/Wizard/Sorcerer/Sorcerer.hpp"
#include "Character/Warrior/Barbarian/Barbarian.hpp"
#include "Weapon/Combat_Weapon/Axe/Axe.hpp"
#include "Weapon/Magic_Item/Potion/Potion.hpp"

using namespace std;

int main() {
    auto wiz = make_shared<Sorcerer>(true);
    auto warr = make_shared<Barbarian>(false);

    wiz->set_custom_name("Ezren");
    warr->set_custom_name("Gorak");

    auto axe = make_unique<Axe>(false);
    auto potion = make_unique<Potion>();

    if (auto* m = dynamic_cast<Magic_Item*>(potion.get())) {
        m->add_user(wiz);
    }

    wiz->add_weapon(std::move(potion));
    warr->add_weapon(std::move(axe));

    cout << "\n-- Initial Character States --\n";
    wiz->display();
    cout << endl;
    warr->display();
    cout << endl;

    cout << "\n-- Battle Begins --\n";

    string axe_name = "Axe";
    string potion_name = "Potion";

    warr->attack(*wiz, axe_name);
    warr->attack(*wiz, axe_name);
    warr->attack(*wiz, axe_name);

    cout << endl;
    wiz->display();
    cout << endl;

    cout << "-- Wizard uses Potion --\n";
    Weapon* potion_ptr = wiz->get_weapon_by_name(potion_name);
    if (potion_ptr && potion_ptr->get_type() == "Magic_Item") {
        auto* m_item = dynamic_cast<Magic_Item*>(potion_ptr);
        if (m_item) m_item->use();
    }

    wiz->display();
    wiz->cast_spell(*warr);
    cout << endl;
    warr->display();

    return 0;
}