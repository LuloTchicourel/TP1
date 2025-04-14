#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Character_Factory/Character_Factory.hpp"

using namespace std;

int main(){
    srand(time(nullptr));

    int num_warriors = 3 + rand() % 5; // rango 3-7
    int num_wizards = 3 + rand() % 5;  // rango 3-7

    vector<shared_ptr<Character>> characters;

    cout << "-- Creating Warriors (" << num_warriors << ") --\n";
    for (int i = 0; i < num_warriors; ++i){
        cout << "Enter warrior type for warrior #" << (i + 1)
        << " (e.g., 'barbarian', leave blank for random): ";
        string type;
        getline(cin, type);

        cout << "Enter number of weapons for warrior #" << (i + 1)
        << " (0-2, leave blank for random): ";
        string weapon_input;
        getline(cin, weapon_input);

        int weapon_count;
        if (weapon_input.empty()){
            weapon_count = rand() % 3; // rango 0-2
        } 
        else {
            weapon_count = stoi(weapon_input);
        }
        shared_ptr<Character> character;
        if (type.empty()){
            character = Character_Factory::create_armed_character("warrior", weapon_count);
        } 
        else {
            character = Character_Factory::create_character_by_type(type, weapon_count);
        }
        if (character){
            character->set_custom_name("Warrior" + to_string(i + 1));
            characters.push_back(character);
        } 
        else {
            cout << "Invalid warrior type, skipping...\n";
        }
    }

    cout << "\n-- Creating Wizards (" << num_wizards << ") --\n";
    for (int i = 0; i < num_wizards; ++i){
        cout << "Enter wizard type for wizard #" << (i + 1)
        << " (e.g., 'sorcerer', leave blank for random): ";
        string type;
        getline(cin, type);
        cout << "Enter number of weapons for wizard #" << (i + 1)
        << " (0-2, leave blank for random): ";
        string weapon_input;
        getline(cin, weapon_input);

        int weapon_count;
        if (weapon_input.empty()){
            weapon_count = rand() % 3;
        } 
        else {
            weapon_count = stoi(weapon_input);
        }

        shared_ptr<Character> character;
        if (type.empty()){
            character = Character_Factory::create_armed_character("wizard", weapon_count);
        } 
        else {
            character = Character_Factory::create_character_by_type(type, weapon_count);
        }

        if (character){
            character->set_custom_name("Wizard" + to_string(i + 1));
            characters.push_back(character);
        } 
        else cout << "Invalid wizard type, skipping...\n";
    }

    cout << "\n-- Final Character List --\n";
    for (auto& c : characters){
        c->display();
        cout << endl;
    }

    return 0;
}