#include "Central_Regional.hpp"
#include "Department.hpp"

Central_Regional::Central_Regional(const string& n) : Organizational_Entity(n) {}

int Central_Regional::get_total_employee_amount(){
    return manager_amount + Department::employee_count(); // devuelve TODOS los empleados
}

int Central_Regional::get_manager_amount() {return manager_amount;}

vector<string> Central_Regional::get_company_names(){
    vector<string> names;
    for (auto it = companies.begin(); it != companies.end(); ++it){
        names.push_back((*it)->name);
    }
    return names;
}

int Central_Regional::get_local_employee_amount() {
    int total = manager_amount;
    vector<shared_ptr<Company>> companies_vec;
    for (auto it = companies.begin(); it != companies.end(); ++it) companies_vec.push_back(*it);
    for (int i = 0; i < companies_vec.size(); i++){
        vector<string> department_names = companies_vec[i]->get_department_names();
        for (int j = 0; j < department_names.size(); j++){
            shared_ptr<Department> dep = companies_vec[i]->get_department(department_names[j]);
            if (dep != nullptr) total += dep->local_employee_count();
        }
    }
    return total;
}

vector<shared_ptr<Middle_Manager>> Central_Regional::get_mid_managers() {return mid_managers;}

vector<shared_ptr<Senior_Manager>> Central_Regional::get_high_managers() {return high_managers;}

void Central_Regional::add_country(const string& name){
    countries.insert(name);
    cout << "Country " << name << " has been added to the list.\n";
}

void Central_Regional::remove_country(const string& name){
    auto it = countries.find(name);
    if (it != countries.end()) {
        countries.erase(it);
        cout << "Country " << name << " removed from the list.\n";
    } 
    else cout << "Country " << name << " was not found in the list.\n";
}

void Central_Regional::add_mid_manager(shared_ptr<Middle_Manager> manager){
    if (mid_managers.size() >= 20){
        cout << "Cannot add more mid-level managers. Maximum capacity (20) reached.\n";
        return;
    }
    mid_managers.push_back(manager);
    manager_amount++;
    cout << "Mid-level manager added successfully.\n";
}

void Central_Regional::add_high_manager(shared_ptr<Senior_Manager> manager){
    if (high_managers.size() >= 5){
        cout << "Cannot add more high-level managers. Maximum capacity (5) reached.\n";
        return;
    }
    high_managers.push_back(manager);
    manager_amount++;
    cout << "High-level manager added successfully.\n";
}

void Central_Regional::remove_mid_manager(shared_ptr<Middle_Manager> manager){
    for (int i = 0; i < mid_managers.size(); i++){
        if (mid_managers[i] == manager){
            mid_managers.erase(mid_managers.begin() + i);
            manager_amount--;
            cout << "Mid-level manager removed.\n";
            return;
        }
    }
    cout << "Mid-level manager not found.\n";
}

void Central_Regional::remove_mid_manager(string manager_name){
    for (int i = 0; i < mid_managers.size(); i++){
        if (mid_managers[i]->name == manager_name){
            mid_managers.erase(mid_managers.begin() + i);
            manager_amount--;
            cout << "Mid-level manager removed by name.\n";
            return;
        }
    }
    cout << "Mid-level manager not found by name.\n";
}

void Central_Regional::remove_high_manager(shared_ptr<Senior_Manager> manager){
    for (int i = 0; i < high_managers.size(); i++){
        if (high_managers[i] == manager){
            high_managers.erase(high_managers.begin() + i);
            manager_amount--;
            cout << "High-level manager removed.\n";
            return;
        }
    }
    cout << "High-level manager not found.\n";
}

void Central_Regional::remove_high_manager(string manager_name){
    for (int i = 0; i < high_managers.size(); i++){
        if (high_managers[i]->name == manager_name){
            high_managers.erase(high_managers.begin() + i);
            manager_amount--;
            cout << "High-level manager removed by name.\n";
            return;
        }
    }
    cout << "High-level manager not found by name.\n";
}

void Central_Regional::add_entity(shared_ptr<Organizational_Entity> sub_entity){
    Organizational_Entity::add_entity(sub_entity);
    shared_ptr<Company> company = dynamic_pointer_cast<Company>(sub_entity);
    if (company) companies.insert(company);    
    cout << "Company added succesfully";
}

Central_Regional::~Central_Regional() {}