#pragma once
#include "../Combat_Weapon.hpp"

class Club : public Combat_Weapon {
public:
    Club();
    
    void set_custom_name(const string& n) override;

    ~Club() override = default;
};