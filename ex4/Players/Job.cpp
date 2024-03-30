#include "Job.h"
#include "../Cards/Card.h"
#include "../Cards/Events.h"
#include "utilities.h"
#include "Player.h"
using std::vector;
using std::string;
const vector<string> Job::JOB_VECTOR = {"Warrior", "Sorcerer"};

/********Job*********/

Job::Job(const std::string& jobName) : m_jobName(jobName) {};

const string& Job::getName() const {
    return m_jobName;
}

bool Job::handleBattle(Player& player, int monsterPower) const {
    return (player.getCombatPower() > monsterPower);
}

int Job::handleSolarEclipse() const {
    /*remove force*/
    return -1;
}

int Job::getPower(const Player& player) const {
    return player.getForce() + player.getLevel();
}

/********Warrior*********/
Warrior::Warrior() : Job(JOB_VECTOR[0]) {};

int Warrior::getPower(const Player& player) const {
    return player.getForce()*2 + player.getLevel();
}


/********Sorcerer*********/
Sorcerer::Sorcerer() : Job(JOB_VECTOR[1]) {};

int Sorcerer::handleSolarEclipse() const {
    /*add force*/
    return 1;
}

