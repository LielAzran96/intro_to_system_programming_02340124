#ifndef EX4_Monster_H
#define EX4_Monster_H
#include <string> 
#include <map>
#include <string>
using std::map;
using std::string;

class Monster {
public:
    // Monster(const std::string name, int power, int loot, int damage) : m_name(name), 
    //     m_power(power), m_loot(loot), m_damage(damage) {};
    Monster();
    ~Monster() = default;
    Monster(const Monster& ) = default;
    Monster& operator=(const Monster& ) = default;
    static const map<string, std::array<int, 3>> monstersMap;
    int getPower() const;
    int getLoot() const;
    int getDamage() const;
    void addMonster(const string& name);
    const string& getName() const;
    class MonsterNotFound : std::exception {};

private:
    std::string m_name;
    int m_power;
    int m_loot;
    int m_damage;
    int m_numberOfMonsters;
};

#endif //EX4_Monster_H