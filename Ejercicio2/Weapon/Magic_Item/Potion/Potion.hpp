#pragma once
#include "../Magic_Item.hpp"

class Potion : public Magic_Item {
public:
    Potion();

    void use() override;
    void set_custom_name(const string& n) override;

    ~Potion() override = default;
};