#include "Company.hpp"

Company::Company(string n) : Organizational_Entity(n) {}

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