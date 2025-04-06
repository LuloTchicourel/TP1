#include "Organizational_Entity.hpp"

class Middle_Manager; class Senior_Manager; class Company;

class Central_Regional : public Organizational_Entity{
private:
    vector<string> countries;
    int employee_amount;
    vector<Middle_Manager*> mid_managers;
    vector<Senior_Manager*> high_managers;
    vector<Company*> companies;
public:
    Central_Regional(string n);

    int get_employee_amount();
    vector<string> get_company_names();
    vector<Middle_Manager*> get_mid_managers();
    vector<Senior_Manager*> get_high_managers();

    ~Central_Regional() override;
};