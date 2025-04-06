#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Organizational_Entity{
protected:
    string name;
    vector<Organizational_Entity*> sub_entities;
public:
    Organizational_Entity(string& n);

    string get_name();
    void add_entity(Organizational_Entity* sub_entity);
    int count();

    virtual ~Organizational_Entity();
};