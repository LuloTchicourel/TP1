#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Weapon {
private:
    virtual void upgrade() = 0;
public:
    virtual string get_name() = 0;
    virtual void set_custom_name(string n) = 0;
    virtual float get_weight() = 0;
    virtual string get_type() = 0;
    virtual void display() = 0;

    virtual ~Weapon() = default;
};