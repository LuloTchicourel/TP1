#include "Organizational_Entity.hpp"

Organizational_Entity::Organizational_Entity(const string& n) {name = n;}

string Organizational_Entity::get_name() {return name;}

void Organizational_Entity::add_entity(shared_ptr<Organizational_Entity> sub_entity) {sub_entities.push_back(sub_entity);}

int Organizational_Entity::count() {return sub_entities.size();}

Organizational_Entity::~Organizational_Entity() {}