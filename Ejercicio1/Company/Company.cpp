#include "Company.hpp"

Company::Company(string n) : Organizational_Entity(n) {}

void Company::change_name(string new_name){
    name = new_name;
    cout << "Company name changed to: " << name << endl;
}

void Company::add_department(shared_ptr<Department> new_department){
    departments.push_back(new_department);
    cout << "Department '" << new_department->name << "' added to company." << endl;
}

void Company::remove_department(shared_ptr<Department> new_department){
    for (int i = 0; i < departments.size(); i++){
        if (departments[i] == new_department){
            departments.erase(departments.begin() + i);
            cout << "Department '" << new_department->name << "' removed from company." << endl;
            return;
        }
    }
    cout << "Department not found..." << endl;
}
shared_ptr<Department> Company::get_department(string n){
    for (int i = 0; i < departments.size(); i++){
        if (departments[i]->name == n) return departments[i];
    }
    cout << "Department not found..." << endl;
}

vector<string> Company::get_department_names(){
    vector<string> names;
    for(int i = 0; i < departments.size(); i++) names.push_back(departments[i]->name);
    return names;
}