#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Employee{
private:
    int seniority;
    float salary;
public:
    Employee(string n, string j, int time, float s);

    string name;
    string job;

    int get_seniority();
    void update_salary(float new_salary);    
    float get_salary();

    virtual ~Employee();
};


