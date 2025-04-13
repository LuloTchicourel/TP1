#pragma once
#include "../Magic_Item.hpp"

class Amulet : public Magic_Item {
public:
    Amulet();

    void use() override;

    ~Amulet() override = default;
};