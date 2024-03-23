#include "Monster.h"
#include "../Players/Player.h"
#include "../utilities.h"

using std::map;
using std::string;

const std::map<std::string, std::map<string, int>> Monster::MONSTER_MAP = {
    {"Goblin", {{"power", 5}, {"loot", 2}, {"damage", 10}}},
    {"Giant", {{"power", 12}, {"loot", 5}, {"damage", 25}}},
    {"Dragon", {{"power", 17}, {"loot", 100}, {"damage", 9001}}},
};

Monster::Monster(const string& name) : Card(name), m_power(0), m_loot(0), m_damage(0) {
    auto it = MONSTER_MAP.find(name);
    if (it != MONSTER_MAP.end()) {
        m_power = it->second.at("power");
        m_loot = it->second.at("loot");
        m_damage = it->second.at("damage");
    } 
}

void Gang::addMonster(const string& name) {
    auto it = MONSTER_MAP.find(name);
    if(it != MONSTER_MAP.end()) {
        m_power += it->second.at("power");
        m_loot += it->second.at("loot");
        m_damage += it->second.at("damage");
    }
    else {
        throw MonsterNotFound();
    }
}

void Gang::setMonstersNumber(int number) {
    m_numberOfMonsters = number;
}

/*Battle Scenario*/
string Monster::applyCard(Player& player) const {
    bool isWin = false;
    isWin = player.handleBattle(m_power, m_loot, m_damage);
    return (isWin) ?  getEncounterWonMessage(player, m_loot) : getEncounterLostMessage(player, m_damage);
}

string Monster::getDescription() const {
    return m_cardName + " (power " + std::to_string(m_power) + ", loot " +
     std::to_string(m_loot) + ", damage " + std::to_string(m_damage) + ")";
}


string Gang::getDescription() const {
    return m_cardName + "Gang of " + std::to_string(m_numberOfMonsters) + " members " + "(power " + std::to_string(m_power) +
    ", loot " + std::to_string(m_loot) + ", damage " + std::to_string(m_damage) + ")";
}
