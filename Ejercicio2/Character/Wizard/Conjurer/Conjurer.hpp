#pragma once
#include "../Wizard.hpp"

class Conjurer : Wizard {
public:
    Conjurer(bool m = false);

    ~Conjurer() override = default;
};