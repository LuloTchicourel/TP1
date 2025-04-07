#include "Organizational_Entity.hpp"
#include "Department.hpp"

class Company : public Organizational_Entity {
private:
    vector<shared_ptr<Department>> departments;
public:
    Company(string n);

    string name;

    void change_name(string new_name);
    void add_department(shared_ptr<Department> new_department);
    void remove_department(shared_ptr<Department> new_department);
    shared_ptr<Department> get_department(string dep);
    vector<string> get_department_names();

    ~Company() override;
};