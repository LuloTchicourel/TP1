#include "../Character.hpp"

class Wizard : public Character {
private:
    bool alive;
    int threshold = 100;
    string name;
    float hp;
    float intelligence;
    float defence;
    int level = 1;
    float experience = 0;
    string type = "Wizard";
    vector<unique_ptr<Weapon>> weapons;
public:
    Wizard();

    void attack(Character& enemy, string& weapon) override;
    bool cast_spell(Character& enemy);
    void receive_damage(float dmg) override;

    string get_name() override;
    bool is_alive() override;
    void set_custom_name(string n) override;
    float get_defence() override;
    float get_hp() override;
    string get_type() override;
    void show_weapons() override;
    void add_weapon(unique_ptr<Weapon> weapon) override;
    void remove_weapon(string n) override;
    void add_xp(float xp);
    Weapon* get_weapon_by_name(string& n) override;
    void display() override;

    ~Wizard() override = default;
};