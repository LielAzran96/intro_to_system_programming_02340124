#include "Job.h"
#include "../Cards/Card.h"
#include "../utilities.h"

/********Job*********/
const string& Job::getName() const {
    return m_jobName;
}

void Job::handleEvent(Player& player, string& result) const {
    player.updateForce(-SolarEclipse::FORCE_TO_UPDATE); //remove force
    result = getSolarEclipseMessage(player, -SolarEclipse::FORCE_TO_UPDATE);
}

int Job::getPower(const Player& player) const {
    return player.getForce() + player.getLevel();
}

/********Warrior*********/
const string Warrior::NAME = "Warrior";

int Warrior::getPower(const Player& player) const {
    return player.getForce()*2 + player.getLevel();
}

/********Sorcerer*********/
const string Sorcerer::NAME = "Sorcerer";

void Sorcerer::handleEvent(Player& player, string& result) const {
    player.updateForce(SolarEclipse::FORCE_TO_UPDATE); //add force
    result = getSolarEclipseMessage(player, SolarEclipse::FORCE_TO_UPDATE);
}

