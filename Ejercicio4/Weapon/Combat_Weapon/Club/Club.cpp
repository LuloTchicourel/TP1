#include "Club.hpp"

Club::Club(){
    name = "Club"; 
    damage = 10; 
}

void Club::set_custom_name(const string& n) {name = n;}
