#pragma once
#include "Organizational_Entity.hpp"
#include "Department.hpp"

class Company : public Organizational_Entity {
private:
    vector<shared_ptr<Department>> departments;
public:
    Company(const string& n, string add);

    string address;

    void change_address(string new_address);
    void add_department(shared_ptr<Department> new_department);
    void remove_department(shared_ptr<Department> new_department);
    shared_ptr<Department> get_department(string dep);
    vector<string> get_department_names();

    ~Company();
};