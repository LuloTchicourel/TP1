**Ejercicio 1:**
g++ -std=c++17 -Wall \
-IOrganizational_Entity \
-IEmployee \
-IManager \
-IManager/Low_Manager \
-IManager/Middle_Manager \
-IManager/Senior_Manager \
-IManager/Team_Leader \
-IDepartment \
-ICompany \
-ICentral_Regional \
Organizational_Entity/Organizational_Entity.cpp \
Employee/Employee.cpp \
Manager/Manager.cpp \
Manager/Low_Manager/Low_Manager.cpp \
Manager/Middle_Manager/Middle_Manager.cpp \
Manager/Senior_Manager/Senior_Manager.cpp \
Manager/Team_Leader/Team_Leader.cpp \
Department/Department.cpp \
Company/Company.cpp \
Central_Regional/Central_Regional.cpp \
main.cpp -o ej1

// agregar sobrecarga para comparar companies //

./ej1

**Ejercicio 2:**