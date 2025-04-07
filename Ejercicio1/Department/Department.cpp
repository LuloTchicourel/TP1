#include "Department.hpp"

Department::Department(string n, string l){
    name = n; location = l;
}

void Department::update_location(string new_location){
    location = new_location;
    cout << "Department location updated to: " << location << endl;
}

void Department::change_name(string new_name){
    name = new_name;
    cout << "Department name changed to: " << name << endl;
}

int Department::employee_count() {return employee_amount;}

int Department::local_employee_count() {return employees.size();}

vector<shared_ptr<Employee>> Department::get_employees() {return employees;}

bool Department::hire(shared_ptr<Employee> employee){
    employees.push_back(employee);
    employee_amount++;
    cout << "Employee has been hired!" << endl;
    return true;
}

bool Department::fire(shared_ptr<Employee> employee){
    for (int i = 0; i < employee_amount; i++){
        if (employee->name == employees[i]->name){
            employees.erase(employees.begin() + 1);
            employee_amount--;
            cout << "Employee has been fired!" << endl;
            return true;
        }
    }
    cout << "Employee not found..." << endl;
    return false;
}
