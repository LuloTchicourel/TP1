#include "Spellbook.hpp"
#include "../../../Character/Character.hpp"

Spellbook::Spellbook() : Magic_Item() {
    // incrementa la stat especial del tipo (strengh / intelligence) un efect_strength%
    name = "Spellbook"; weight = 4; uses = 5;
    switch (rarity){
        case Rarity::Common:
            effect_strength = 10;
            break;
        case Rarity::Rare:
            effect_strength = 18;
            break;
        case Rarity::Epic:
            effect_strength = 25;
            break;
        case Rarity::Legendary:
            effect_strength = 30;
            break;
    }
}

void Spellbook::use(){
    if (uses == 0){
        cout << "No uses available for this...\n";
        return;
    }
    if (!player || !player->is_alive()){
        cout << "Cannot apply buff. Player is null or dead.\n";
        return;
    }
    if (player->get_type() == "Warrior") Magic_Item::apply_to("str", effect_strength);
    if (player->get_type() == "Wizard") Magic_Item::apply_to("int", effect_strength);
    uses--;
}