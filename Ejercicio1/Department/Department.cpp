#include "Department.hpp"

Department::Department(string n, string l){
    name = n; location = l;
}

int Department::employee_count() {return employee_amount;}

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
