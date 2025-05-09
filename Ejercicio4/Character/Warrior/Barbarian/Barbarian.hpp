#pragma once
#include "../Warrior.hpp"

class Barbarian : public Warrior {
public:
    Barbarian();
    
    void set_custom_name(const string& n) override;

    ~Barbarian() override = default;
};