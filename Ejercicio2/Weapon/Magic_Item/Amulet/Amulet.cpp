#include "Amulet.hpp"
#include "../../../Character/Character.hpp"

Amulet::Amulet() : Magic_Item() {
    // Sube la defensa un effect_strength%
    name = "Amulet"; weight = 0.6; uses = 2;
    switch (rarity){
        case Rarity::Common:
            effect_strength = 5;
            break;
        case Rarity::Rare:
            effect_strength = 11;
            break;
        case Rarity::Epic:
            effect_strength = 16;
            break;
        case Rarity::Legendary:
            effect_strength = 23;
            break;
    }
}

void Amulet::use(){
    if (uses == 0){
        cout << "No uses available for this...\n";
        return;
    }
    if (!player || !player->is_alive()){
        cout << "Cannot apply buff. Player is null or dead.\n";
        return;
    }
    Magic_Item::apply_to("def", effect_strength);
    uses--;
}

void Amulet::set_custom_name(const string& n) {name = n;}