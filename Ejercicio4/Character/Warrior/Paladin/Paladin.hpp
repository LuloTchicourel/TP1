#pragma once
#include "../Warrior.hpp"

class Paladin : public Warrior {
public:
    Paladin();
    
    void set_custom_name(const string& n) override;

    ~Paladin() override = default;
};