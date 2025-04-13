#pragma once
#include "../Wizard.hpp"

class Sorcerer : public Wizard {
public:
    Sorcerer(bool m = false);

    ~Sorcerer() override = default;
};