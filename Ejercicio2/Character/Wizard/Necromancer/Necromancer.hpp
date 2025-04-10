#pragma once
#include "../Wizard.hpp"

class Necromancer : Wizard {
public:
    Necromancer(bool m = false);

    ~Necromancer() override = default;
};