#pragma once
#include "../Magic_Item.hpp"

class Spellbook : public Magic_Item {
public:
    Spellbook();

    void use() override;
    void set_custom_name(const string& n) override;

    ~Spellbook() override = default;
};