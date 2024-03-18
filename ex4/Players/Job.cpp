#include "Job.h"
#include "../Cards/Card.h"
#include "../utilities.h"

/********Job*********/
const string& Job::getName() const {
    return m_jobName;
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
const string Warrior::NAME = "Warrior";

int Warrior::getPower(const Player& player) const {
    return player.getForce()*2 + player.getLevel();
}

/********Sorcerer*********/
const string Sorcerer::NAME = "Sorcerer";

void Sorcerer::handleEvent(Player& player, string& result) const {
    /*add force*/
    if(player.updateForce(SolarEclipse::FORCE_TO_UPDATE)) {
        result = getSolarEclipseMessage(player, SolarEclipse::FORCE_TO_UPDATE);
    }
    else {
        result = getSolarEclipseMessage(player, 0);
    }
}

