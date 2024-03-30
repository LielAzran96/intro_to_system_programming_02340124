#include "Monster.h"
#include "../Players/Player.h"
#include "utilities.h"

using std::string;


Monster::Monster(const string& name, int power, int loot, int damage) : Card(name), m_power(power), m_loot(loot), m_damage(damage)
{};

string Monster::getDescription() const {
    return m_cardName + " (power " + std::to_string(m_power) + ", loot " +
     std::to_string(m_loot) + ", damage " + std::to_string(m_damage) + ")";
}

/*Battle Scenario*/
string Monster::applyCard(Player& player) const {
    bool isWin = true;
    if(player.getJob().handleBattle(player, m_power)) {
        player.levelUp();
        player.addCoins(m_loot);
        isWin = true;
    }
    /*loosing the battle*/
    else {
        player.damageHP(m_damage);
        isWin = false;
    }
    return (isWin) ?  getEncounterWonMessage(player, m_loot) : getEncounterLostMessage(player, m_damage);
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

/**Gang**/
Gang::Gang() : Monster(), m_numberOfMonsters(0) {};

void Gang::addMonster(const Monster& monster) {
    m_power += monster.getPower();
    m_loot += monster.getLoot();
    m_damage += monster.getDamage();
    m_numberOfMonsters++;
}

int Gang::getNumberOfMonsters() const {
    return m_numberOfMonsters;
}
void Gang::setGangName() {
    m_cardName = "Gang of " + std::to_string(m_numberOfMonsters) + " members";
}
