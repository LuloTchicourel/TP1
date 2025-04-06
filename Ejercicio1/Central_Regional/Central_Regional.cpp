#include "Central_Regional.hpp"

Central_Regional::Central_Regional(string n) : Organizational_Entity(n) {}

int Central_Regional::get_employee_amount() {return employee_amount;}

vector<string> Central_Regional::get_company_names(){
    vector<string> names;
    for (int i = 0; i < companies.size(); i++) names.push_back(companies[i]->name);
    return names;
}

vector<shared_ptr<Employee>> Central_Regional::get_mid_managers() {return mid_managers;}

vector<shared_ptr<Employee>> Central_Regional::get_high_managers() {return high_managers;}

void Central_Regional::add_mid_manager(shared_ptr<Employee> manager) {mid_managers.push_back(manager);}

void Central_Regional::add_high_manager(shared_ptr<Employee> manager) {high_managers.push_back(manager);}

