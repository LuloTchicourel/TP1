#pragma once
#include "../Combat_Weapon.hpp"

class Club : public Combat_Weapon {
public:
    Club(bool special = false);

    ~Club() override = default;
};