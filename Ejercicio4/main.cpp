#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Character/Character.hpp"
#include "Character_Factory/Character_Factory.hpp"

using namespace std;

int main(){
    srand(time(nullptr));

    vector<string> options = {
        "Sorcerer",
        "Warlock",
        "Conjurer",
        "Necromancer",
        "Barbarian",
        "Knight",
        "Mercenary",
        "Paladin",
        "Gladiator"
    };

    vector<string> weapons = {
        "Axe",
        "Sword",
        "Spear",
        "Double_Axe"
    };

    vector<string> attack_options = {
        "Golpe Fuerte",        // 0
        "Golpe Rapido",        // 1
        "Defensa y Golpe"      // 2
    };

    cout << "What type of character do you want? (blank for random)" << endl;
    cout << "Options:" << endl;
    for (int i = 0; i < options.size(); ++i){
        cout << "  " << i << ". " << options[i] << endl;
    }
    string character_answer;
    getline(cin, character_answer);

    cout << "What type of weapon? (blank for random)" << endl;
    cout << "Options:" << endl;
    for (int i = 0; i < weapons.size(); ++i){
        cout << "  " << i << ". " << weapons[i] << endl;
    }
    string weapon_answer;
    getline(cin, weapon_answer);

    unique_ptr<Character> character;

    if (character_answer.empty()){
        character = Character_Factory::create_random_character();
        if (weapon_answer.empty()){
            unique_ptr<Combat_Weapon> weapon = Character_Factory::create_random_weapon();
            character->add_weapon(std::move(weapon));
        } 
        else {
            character = Character_Factory::create_character_by_type(character->get_name(), weapons[stoi(weapon_answer) % 4]);
        }
    }
    else {
        string character_type = options[stoi(character_answer) % 8];

        if (weapon_answer.empty()){
            unique_ptr<Combat_Weapon> w = Character_Factory::create_random_weapon();
            character = Character_Factory::create_character_by_type(character_type, w->get_name());
        } 
        else {
            string weapon_type = weapons[stoi(weapon_answer) % weapons.size()];
            character = Character_Factory::create_character_by_type(character_type, weapon_type);
        }
    }

    unique_ptr<Character> ai_character = Character_Factory::create_random_character();
    ai_character->add_weapon(Character_Factory::create_random_weapon());

    cout << "\n=== BATTLE STARTS ===" << endl;
    character->display();
    ai_character->display();
    
    while (character->is_alive() && ai_character->is_alive()){
        cout << "\nPlayer has " << character->get_hp()
        << " HP | AI has " << ai_character->get_hp() << " HP." << endl;
    
        cout << "Choose your attack: (0) Golpe Fuerte, (1) Golpe Rapido, (2) Defensa y Golpe: ";
        string input;
        getline(cin, input);
        int player_choice = stoi(input) % 3;
        int ai_choice = rand() % 3;
    
        cout << "\nYou chose: " << attack_options[player_choice] << endl;
        cout << "AI chose: " << attack_options[ai_choice] << endl;
    
        if (player_choice == ai_choice){
            cout << "It's a tie. No damage dealt." << endl;
            continue;
        }
    
        bool player_wins =
            (player_choice == 0 && ai_choice == 1) || // Fuerte > Rapido
            (player_choice == 1 && ai_choice == 2) || // Rapido > Bloqueo
            (player_choice == 2 && ai_choice == 0);   // Bloqueo > Fuerte
    
        if (player_wins){
            character->attack(*ai_character);
        } 
        else {
            ai_character->attack(*character);
        }
    
        cout << character->get_name() << " has " << character->get_hp()
        << " HP | " << ai_character->get_name()
        << " has " << ai_character->get_hp() << " HP." << endl;
    }

    cout << "\n=== BATTLE ENDED ===" << endl;
    if (character->is_alive()) {
        cout << "You won the battle!" << endl;
    } 
    else {
        cout << "The AI won the battle!" << endl;
    }

    return 0;
}