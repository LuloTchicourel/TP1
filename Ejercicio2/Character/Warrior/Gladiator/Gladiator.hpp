#pragma once
#include "../Warrior.hpp"

class Gladiator : public Warrior {
public:
    Gladiator(bool l = false);

    void set_custom_name(const string& n) override;

    ~Gladiator() override = default;
};