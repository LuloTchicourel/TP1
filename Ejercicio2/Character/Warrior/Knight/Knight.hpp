#pragma once
#include "../Warrior.hpp"

class Knight : public Warrior {
public:
    Knight(bool l = false);

    void set_custom_name(const string& n) override;

    ~Knight() override = default;
};