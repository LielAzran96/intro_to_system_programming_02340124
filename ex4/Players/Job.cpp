#include "Job.h"
#include "../Cards/Card.h"
#include "../Cards/Events.h"
#include "../utilities.h"
#include "Player.h"
using std::vector;
using std::string;
// class SolarEclipse;
const vector<string> Job::JOB_VECTOR = {"Warrior", "Sorcerer"};

/********Job*********/
const string& Job::getName() const {
    return m_jobName;
}

bool Job::handleBattle(Player& player, int monsterPower, int monsterLoot, int monsterDamage) const {
    bool isWin = true;
    if(player.getCombatPower() > monsterPower) {
        player.levelUp();
        player.addCoins(monsterLoot);
        isWin = true;
    }
    /*loosing the battle*/
    else {
        player.damageHP(monsterDamage);
        isWin = false;
    }
    return isWin;
}

void Job::handleEvent(Player& player, string& result) const {
    /*remove force*/
    if(player.updateForce(-SolarEclipse::FORCE_TO_UPDATE)){
        result = getSolarEclipseMessage(player, -SolarEclipse::FORCE_TO_UPDATE);
    } 
    else {
        result = getSolarEclipseMessage(player, 0);
    }
}

int Job::getPower(const Player& player) const {
    return player.getForce() + player.getLevel();
}

/********Warrior*********/
int Warrior::getPower(const Player& player) const {
    return player.getForce()*2 + player.getLevel();
}



/********Sorcerer*********/
void Sorcerer::handleEvent(Player& player, string& result) const {
    /*add force*/
    if(player.updateForce(SolarEclipse::FORCE_TO_UPDATE)) {
        result = getSolarEclipseMessage(player, SolarEclipse::FORCE_TO_UPDATE);
    }
    else {
        result = getSolarEclipseMessage(player, 0);
    }
}

