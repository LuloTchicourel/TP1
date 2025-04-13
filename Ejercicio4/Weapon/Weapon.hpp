#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Weapon {
public:
    Weapon() = default;

    virtual string get_name() = 0;
    virtual string get_type() = 0;
    virtual void display() = 0;

    virtual ~Weapon() = default;
};