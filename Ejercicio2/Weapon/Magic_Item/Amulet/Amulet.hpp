#pragma once
#include "../Magic_Item.hpp"

class Amulet : public Magic_Item {
public:
    Amulet();

    void use() override;
    void set_custom_name(const string& n) override;

    ~Amulet() override = default;
};