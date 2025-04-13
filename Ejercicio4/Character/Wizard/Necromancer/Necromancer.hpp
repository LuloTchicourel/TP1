#pragma once
#include "../Wizard.hpp"

class Necromancer : public Wizard {
public:
    Necromancer();
    
    void set_custom_name(const string& n) override;

    ~Necromancer() override = default;
};