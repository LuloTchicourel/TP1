#include "Employee.hpp"

Employee::Employee(string n, string j, int time, float s){
    name = n; job = j; seniority = time; salary = s;
}

int Employee::get_seniority() {return seniority;}

void Employee::update_seniority(int increase){
    if (increase > 0){
        seniority += increase;
        cout << "Seniority updated successfully to: " << seniority << " years." << endl;
    } 
    else cout << "Invalid increase value. Must be greater than 0." << endl;
}

void Employee::update_salary(float new_salary){
    if (new_salary > 0){
        salary = new_salary;
        cout << "Salary updated succesfully." << endl;
        return;
    }
    cout << "Please provide a valid salary ( > 0 )." << endl;
}

float Employee::get_salary() {return salary;}

void Employee::change_job(string new_job){
    job = new_job;
    cout << "Job updated successfully to: " << job << endl;
}

void Employee::change_name(string new_name){
    name = new_name;
    cout << "Name updated successfully to: " << name << endl;
}

