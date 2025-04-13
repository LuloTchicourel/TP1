#pragma once
#include "../Wizard.hpp"

class Conjurer : public Wizard {
public:
    Conjurer(bool m = false);
    
    void set_custom_name(const string& n) override;

    ~Conjurer() override = default;
};