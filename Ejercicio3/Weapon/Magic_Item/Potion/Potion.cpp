#include "Potion.hpp"
#include "../../../Character/Character.hpp"

Potion::Potion() : Magic_Item() {
    // Cura la vida de effect_strength
    name = "Potion"; weight = 1.4; uses = 3;
    switch (rarity){
        case Rarity::Common:
            effect_strength = 210;
            break;
        case Rarity::Rare:
            effect_strength = 290;
            break;
        case Rarity::Epic:
            effect_strength = 340;
            break;
        case Rarity::Legendary:
            effect_strength = 400;
            break;
    }
}
void Potion::use(){
    if (uses == 0){
        cout << "No uses available for this...\n";
        return;
    }
    if (!player || !player->is_alive()){
        cout << "Cannot apply buff. Player is null or dead.\n";
        return;
    }
    Magic_Item::apply_to("hp", effect_strength);
    uses--;
}