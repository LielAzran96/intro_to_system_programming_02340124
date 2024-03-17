#include "Monster.h"
#include <array>


const map<string, std::array<int, 3>> Monster::monstersMap = {
    {"Goblin", {5, 2, 10}},
    {"Giant", {12, 5, 25}},
    {"Dragon", {17, 100, 9001}},
    {"Gang", {0, 0, 0}}
};

Monster::Monster() : m_name(""), m_power(0), m_loot(0), m_damage(0), m_numberOfMonsters(0) {
    // map<string, std::array<int, 3>> ::const_iterator it;
    // it = monstersMap.find(name);
    // if(it != monstersMap.end()) {
    //     m_name = name;
    // }
    // else {
    //     throw MonsterNotFound();
    //}
};

void Monster::addMonster(const string& name) {
    map<string, std::array<int, 3>> ::const_iterator it;
    it = monstersMap.find(name);
    if(it != monstersMap.end()) {
        m_name = name;
        m_power += it->second[0];
        m_loot += it->second[1];
        m_damage += it->second[2];
        m_numberOfMonsters++;
    }
    else {
        throw MonsterNotFound();
    }
}

const string& Monster::getName() const {
    return m_name;
}

int Monster::getPower() const {
    return m_power;
}

int Monster::getLoot() const {
    return m_loot;
}

int Monster::getDamage() const {
    return m_damage;
}

// int main() {
//     Monster monster("Goblin");
//     monster.addMonster(monster.getName());

//     Monster monster2("Gang");
//     std::vector<string> monsters = {"Goblin", "Dragon", "Goblin"};
//     for(string name:monsters) {
//         monster2.addMonster(name);
//     }
    
//     return 0;
// }