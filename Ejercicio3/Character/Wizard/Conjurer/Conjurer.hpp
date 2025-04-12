#pragma once
#include "../Wizard.hpp"

class Conjurer : public Wizard {
public:
    Conjurer(bool m = false);

    ~Conjurer() override = default;
};