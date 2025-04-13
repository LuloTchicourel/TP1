#pragma once
#include "../Warrior.hpp"

class Mercenary : public Warrior {
public:
    Mercenary();
    
    void set_custom_name(const string& n) override;

    ~Mercenary() override = default;
};