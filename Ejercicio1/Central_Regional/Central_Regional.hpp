#include "Organizational_Entity.hpp"
#include "Employee.hpp"


class Central_Regional : public Organizational_Entity{
private:
    int employee_amount;
    vector<shared_ptr<Employee>> mid_managers;
    vector<shared_ptr<Employee>> high_managers;
    vector<shared_ptr<Organizational_Entity>> companies;
public:
    Central_Regional(string n);

    vector<string> countries;

    int get_employee_amount();
    vector<string> get_company_names();
    vector<shared_ptr<Employee>> get_mid_managers();
    vector<shared_ptr<Employee>> get_high_managers();
    void add_mid_manager(shared_ptr<Employee> manager);
    void add_high_manager(shared_ptr<Employee> manager);

    ~Central_Regional() override;
};