#pragma once
#include "../Magic_Item.hpp"

class Staff : public Magic_Item {
public:
    Staff();

    void use() override;
    void set_custom_name(const string& n) override;

    ~Staff() override = default;
};

