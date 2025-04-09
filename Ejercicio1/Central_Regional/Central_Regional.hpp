#pragma once
#include "Company.hpp"
#include "Senior_Manager.hpp"
#include "Middle_Manager.hpp"

class Central_Regional : public Organizational_Entity{
private:
    int manager_amount;
    vector<shared_ptr<Middle_Manager>> mid_managers;
    vector<shared_ptr<Senior_Manager>> high_managers;
    set<shared_ptr<Company>> companies;
public:
    Central_Regional(const string& n);

    set<string> countries;

    int get_total_employee_amount();
    int get_local_employee_amount(); // en vez de todos, devuelve los atados a esta central regional y sus derivadas
    int get_manager_amount();
    vector<string> get_company_names();
    vector<shared_ptr<Middle_Manager>> get_mid_managers();
    vector<shared_ptr<Senior_Manager>> get_high_managers();
    void add_country(const string& name);
    void remove_country(const string& name);
    void add_mid_manager(shared_ptr<Middle_Manager> manager);
    void add_high_manager(shared_ptr<Senior_Manager> manager);
    void remove_mid_manager(shared_ptr<Middle_Manager> manager);
    void remove_mid_manager(string manager_name);
    void remove_high_manager(shared_ptr<Senior_Manager> manager);
    void remove_high_manager(string manager_name);
    void add_entity(shared_ptr<Organizational_Entity> sub_entity) override;

    ~Central_Regional();
};