#pragma once
#include "../Wizard.hpp"

class Necromancer : public Wizard {
public:
    Necromancer(bool m = false);

    ~Necromancer() override = default;
};