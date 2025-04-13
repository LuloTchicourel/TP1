#pragma once
#include "../Magic_Item.hpp"

class Spellbook : public Magic_Item {
public:
    Spellbook();

    void use() override;

    ~Spellbook() override = default;
};