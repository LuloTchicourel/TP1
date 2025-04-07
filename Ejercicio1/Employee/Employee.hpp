#include <iostream>
#include <string>

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
    void update_seniority(int increase); 
    // update_seniority realisticamente deberia ser llamada una vez por año automaticamente
    void update_salary(float new_salary);    
    float get_salary();
    void change_job(string new_job);
    void change_name(string new_name);

    virtual ~Employee();
};


