#include "Employee.hpp"
#include "Manager.hpp"
#include "Middle_Manager.hpp"
#include "Senior_Manager.hpp"
#include "Low_Manager.hpp"
#include "Team_Leader.hpp"
#include "Department.hpp"
#include "Company.hpp"
#include "Central_Regional.hpp"

void test1(){
    shared_ptr<Employee> e1 = make_shared<Employee>("Alice", "Engineer", 2, 50000);
    shared_ptr<Employee> e2 = make_shared<Employee>("Bob", "Analyst", 3, 47000);
    shared_ptr<Employee> e3 = make_shared<Employee>("Cathy", "Designer", 1, 48000);

    shared_ptr<Middle_Manager> mm1 = make_shared<Middle_Manager>("Mila", "Manager", 5, 80000, 7000, Levels::MID);
    shared_ptr<Senior_Manager> sm1 = make_shared<Senior_Manager>("Sarah", "Sr Manager", 10, 100000, 15000, Levels::HIGH);

    shared_ptr<Department> dep1 = make_shared<Department>("Tech", "Buenos Aires");
    dep1->hire(e1);
    dep1->hire(e2);

    shared_ptr<Department> dep2 = make_shared<Department>("Design", "Córdoba");
    dep2->hire(e3);

    shared_ptr<Company> comp1 = make_shared<Company>("Globant", "Avenida del Libertador 5478");
    comp1->add_department(dep1);
    comp1->add_department(dep2);

    Central_Regional cr("South America");
    cr.add_country("Argentina");
    cr.add_country("Chile");
    cr.add_high_manager(sm1);
    cr.add_mid_manager(mm1);

    cr.add_entity(comp1);

    cout << "\n--- CENTRAL REGIONAL ---" << endl;
    cout << "Total Employees: " << cr.get_total_employee_amount() << endl;
    cout << "Local Employees (under this Central): " << cr.get_local_employee_amount() << endl;

    cout << "\nCompanies in Central Regional:" << endl;
    for (const string& name : cr.get_company_names()){
        cout << " - " << name << endl;
    }

    cout << "\nDepartments in Globant:" << endl;
    for (const string& dname : comp1->get_department_names()){
        cout << " - " << dname << endl;
    }
    cout << endl;
}

void test2(){
    Central_Regional cr("LatAm");

    shared_ptr<Middle_Manager> m1 = make_shared<Middle_Manager>("M1", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m2 = make_shared<Middle_Manager>("M2", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m3 = make_shared<Middle_Manager>("M3", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m4 = make_shared<Middle_Manager>("M4", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m5 = make_shared<Middle_Manager>("M5", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m6 = make_shared<Middle_Manager>("M6", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m7 = make_shared<Middle_Manager>("M7", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m8 = make_shared<Middle_Manager>("M8", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m9 = make_shared<Middle_Manager>("M9", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m10 = make_shared<Middle_Manager>("M10", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m11 = make_shared<Middle_Manager>("M11", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m12 = make_shared<Middle_Manager>("M12", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m13 = make_shared<Middle_Manager>("M13", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m14 = make_shared<Middle_Manager>("M14", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m15 = make_shared<Middle_Manager>("M15", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m16 = make_shared<Middle_Manager>("M16", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m17 = make_shared<Middle_Manager>("M17", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m18 = make_shared<Middle_Manager>("M18", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m19 = make_shared<Middle_Manager>("M19", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m20 = make_shared<Middle_Manager>("M20", "Mid", 4, 50000, 5000, Levels::MID);
    shared_ptr<Middle_Manager> m21 = make_shared<Middle_Manager>("M21", "Mid", 4, 50000, 5000, Levels::MID);

    vector<shared_ptr<Middle_Manager>> mids = {
        m1, m2, m3, m4, m5, m6, m7, m8, m9, m10,
        m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21
    };

    for (auto& m : mids)
        cr.add_mid_manager(m);

    shared_ptr<Senior_Manager> s1 = make_shared<Senior_Manager>("S1", "Senior", 10, 90000, 10000, Levels::HIGH);
    shared_ptr<Senior_Manager> s2 = make_shared<Senior_Manager>("S2", "Senior", 10, 90000, 10000, Levels::HIGH);
    shared_ptr<Senior_Manager> s3 = make_shared<Senior_Manager>("S3", "Senior", 10, 90000, 10000, Levels::HIGH);
    shared_ptr<Senior_Manager> s4 = make_shared<Senior_Manager>("S4", "Senior", 10, 90000, 10000, Levels::HIGH);
    shared_ptr<Senior_Manager> s5 = make_shared<Senior_Manager>("S5", "Senior", 10, 90000, 10000, Levels::HIGH);
    shared_ptr<Senior_Manager> s6 = make_shared<Senior_Manager>("S6", "Senior", 10, 90000, 10000, Levels::HIGH);

    vector<shared_ptr<Senior_Manager>> seniors = {s1, s2, s3, s4, s5, s6};

    for (auto& s : seniors)
        cr.add_high_manager(s);
    cout << endl;
}


int main(){
    test1();
    test2();

    return 0;
}