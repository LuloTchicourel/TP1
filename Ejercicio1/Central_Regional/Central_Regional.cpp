#include "Central_Regional.hpp"

Central_Regional::Central_Regional(string n) : Organizational_Entity(n) {}

int Central_Regional::get_employee_amount() {return employee_amount;}

vector<string> Central_Regional::get_company_names(){
    vector<string> names;
    for (int i = 0; i < companies.size(); i++){
        names.push_back(companies[i].get_name()); // deberia funcionar cuando implemente company
    }
    return names;
}


