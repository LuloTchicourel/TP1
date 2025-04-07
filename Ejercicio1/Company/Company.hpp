#include "Organizational_Entity.hpp"
#include "Department.hpp"

class Company : public Organizational_Entity {
private:
    vector<shared_ptr<Department>> departments;
public:
    Company(string n);

    string name;

    shared_ptr<Department> get_department(string dep);
    vector<string> get_department_names();

    ~Company() override;
};