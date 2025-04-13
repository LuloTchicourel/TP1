#pragma once
#include "../Warrior.hpp"

class Knight : public Warrior {
public:
    Knight();
    
    void set_custom_name(const string& n) override;

    ~Knight() override = default;
};