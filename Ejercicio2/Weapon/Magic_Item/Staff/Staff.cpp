#include "Staff.hpp"
#include "../../../Character/Character.hpp"


Staff::Staff() : Magic_Item() {
    // suma un uso aleatoriamente a otro Magic_Item o uno a todos si es Epic o Legendary
    name = "Staff"; weight = 0; uses = 0;
    switch (rarity){
        case Rarity::Common:
            effect_strength = 1; // +1 a un random
            break;
        case Rarity::Rare:
            effect_strength = 2; // +2 a un random
            break;
        case Rarity::Epic:
            effect_strength = 3; // +1 a todos
            break;
        case Rarity::Legendary:
            effect_strength = 4; // +2 a todos
            break;
    }
}

void Staff::use(){
    if (uses == 0) {
        cout << "No uses left.\n";
        return;
    }
    if (!player || !player->is_alive()){
        cout << "Cannot apply buff. Player is null or dead.\n";
        return;
    }
    bool r;
    switch (rarity) {
        case Rarity::Common:
            r = apply_staff_effect(1, false);
            if(r) uses--;
            break;
        case Rarity::Rare:
            r = apply_staff_effect(2, false);
            if(r) uses--;
            break;
        case Rarity::Epic:
            r = apply_staff_effect(1, true);
            if(r) uses--;
            break;
        case Rarity::Legendary:
            r = apply_staff_effect(2, true);
            if(r) uses--;
            break;
    }
}