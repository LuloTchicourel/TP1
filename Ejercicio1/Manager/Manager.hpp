#include "Employee.hpp"

class Manager : public Employee {
private:
    float bonus;
    string level;
public:
    Manager(string n, string j, int time, float s, float b, string lvl);

    bool update_bonus(float new_bonus);
    float get_bonus();
    bool set_level(string lvl);

    ~Manager() override;
};