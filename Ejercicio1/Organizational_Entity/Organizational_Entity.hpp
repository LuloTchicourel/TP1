#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Organizational_Entity{
private:
    vector<shared_ptr<Organizational_Entity>> sub_entities;
public:
    Organizational_Entity(string& n);

    string name;

    string get_name();
    void add_entity(shared_ptr<Organizational_Entity> sub_entity);
    int count();

    virtual ~Organizational_Entity();
};