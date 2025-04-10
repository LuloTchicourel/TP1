#pragma once
#include "../Wizard.hpp"

class Sorcerer : Wizard {
public:
    Sorcerer(bool m = false);

    ~Sorcerer() override = default;
};