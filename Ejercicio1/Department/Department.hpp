#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Employee.hpp"

using namespace std;

class Department{
private:
    vector<shared_ptr<Employee>> employees;
    static int employee_amount;
    int local_employee_amount;
public:
    Department(string n, string l);

    string name;
    string location;

    void update_location(string new_location);
    void change_name(string new_name);
    static int employee_count();
    int local_employee_count();
    vector<shared_ptr<Employee>> get_employees();
    bool hire(shared_ptr<Employee> employee);
    bool fire(shared_ptr<Employee> employee);

    ~Department();
};
