#include "../Character.hpp"

class Wizard : public Character {
private:
    string name;
    float hp;
    float intelligence;
    float defence;
    string type = "Wizard";
    vector<unique_ptr<Weapon>> weapons;
public:
    Wizard();

    void attack(Character& enemy, string& weapon) override;
    bool cast_spell(Character& enemy);
    void receive_damage(float dmg) override;

    string get_name() override;
    void set_custom_name(string n) override;
    float get_hp() override;
    string get_type() override;
    string show_weapons() override;
    void add_weapon(unique_ptr<Weapon> weapon) override;
    void remove_weapon(string t) override;
    Weapon* get_weapon_by_name(string& n) override;
    void display() override;

    ~Wizard() override = default;
};