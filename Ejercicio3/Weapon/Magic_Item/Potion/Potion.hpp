#pragma once
#include "../Magic_Item.hpp"

class Potion : public Magic_Item {
public:
    Potion();

    void use() override;

    ~Potion() override = default;
};