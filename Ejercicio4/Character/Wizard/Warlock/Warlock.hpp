#pragma once
#include "../Wizard.hpp"

class Warlock : public Wizard {
public:
    Warlock();
    
    void set_custom_name(const string& n) override;

    ~Warlock() override = default;
};