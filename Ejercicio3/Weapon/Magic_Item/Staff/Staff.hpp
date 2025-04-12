#pragma once
#include "../Magic_Item.hpp"

class Staff : public Magic_Item {
public:
    Staff();

    void use() override;

    ~Staff() override = default;
};

