#pragma once
#include "../Wizard.hpp"

class Sorcerer : public Wizard {
public:
    Sorcerer();
    
    void set_custom_name(const string& n) override;

    ~Sorcerer() override = default;
};