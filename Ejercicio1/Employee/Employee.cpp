#include "Employee.hpp"

Employee::Employee(string n, string j, int time, float s){
    name = n; job = j; seniority = time; salary = s;
}

int Employee::get_seniority() {return seniority;}

void Employee::update_salary(float new_salary){
    if (new_salary > 0){
        salary = new_salary;
        cout << "Salary updated succesfully." << endl;
        return;
    }
    cout << "Please provide a valid salary ( > 0 )." << endl;
}

float Employee::get_salary() {return salary;}


