#pragma once
#include "../Wizard.hpp"

class Warlock : public Wizard {
public:
    Warlock(bool m = false);

    ~Warlock() override = default;
};