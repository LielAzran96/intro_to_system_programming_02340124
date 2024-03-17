#include "Card.h"
#include <iostream>
#include "../Players/Player.h"
#include "../Players/Behavior.h"
#include "../Players/Job.h"
#include "../utilities.h"
#include <sstream>

// static bool isNumber(const string& str) {
//     try {
//         size_t position;
//         std::stoi(str, &position);
//         return position == str.length();  // Check if entire string was consumed
//     } 
//     catch(...) {
//         return false;  // Conversion failed
//     }
// }

static bool isNumber(const std::string& str, int& number) {
    std::istringstream iss(str);
    return !(iss >> number).fail() && iss.eof();
}

static unique_ptr<Encounter> createMonster(const string& cardName) {
    std::istringstream monsterDetails(cardName);
    string token;
    bool secondCall = true;
    int numberOfMonsters = 0;
    int counter = 0;
    unique_ptr<Encounter> encounterCard(new Encounter());
    //first token
    if(monsterDetails >> token) {
        try {
            encounterCard->getMonster().addMonster(token);
            encounterCard->setCardName(token);
        }
        catch(const Monster::MonsterNotFound& ) {
            return nullptr;
        }       
    }   
    //Gang
    while(monsterDetails >> token) {
        if(secondCall) {
            if(isNumber(token , numberOfMonsters)) {
                secondCall = false;
            } 
            else {
                return nullptr;
            }
        }
        else {
            try {
                encounterCard->getMonster().addMonster(token);
                counter++;
            }
            catch(const Monster::MonsterNotFound& ) {
                return nullptr;
            }
        }            
    }
    /*check if the number of monsters in the file matches the actuall number of monsters in the file */
    return (counter == numberOfMonsters) ? std::move(encounterCard) : nullptr;
}


unique_ptr<Card> Card::createCard(const string& cardName) {
    if(cardName == "SolarEclipse") {
        return unique_ptr<SolarEclipse>(new SolarEclipse());
    }
    else if(cardName == "PotionsMerchant") {
        return unique_ptr<PotionsMerchant>(new PotionsMerchant());
    }
    else {
        return createMonster(cardName);
    }
}

void Encounter::setCardName(const string& cardName) {
    m_cardName = cardName;
}

/*Battle Scenario*/
string Encounter::applyCard(Player& player) const {
    if(player.getCombatPower() >= m_monster->getPower()) {
        player.levelUp();
        player.addCoins(m_monster->getLoot());
        return getEncounterWonMessage(player, m_monster->getLoot());
    }
    /*loosing the battle*/
    else {
        player.damageHP(m_monster->getDamage());
        return getEncounterLostMessage(player, m_monster->getDamage());
    }
}


Monster& Encounter::getMonster() {
    return *m_monster;
}

/*Event Scenario - SolarEclipse*/
const std::string SolarEclipse::NAME ="SolarEclipse";

string SolarEclipse::applyCard(Player& player) const {
    string result; 
    player.getJob().handleEvent(player, result);
    return result;
}

/*Event Scenario - PotionsMerchant*/
const std::string PotionsMerchant::NAME = "PotionsMerchant";

string PotionsMerchant::applyCard(Player& player) const {
    string result; 
    player.getBehavior().handleEvent(player, result);
    return result;
}

string Card::getDescription() const {
    return m_cardName;
}


string Encounter::getDescription() const {
    return m_monster->getName() + "(power" + std::to_string(m_monster->getPower()) + ", " + "loot " +
     std::to_string(m_monster->getLoot()) + ", " + "damage " + std::to_string(m_monster->getDamage()) + ")";
}

// int main() {
//     Player player("lil");
//     player.setBehavior("Responsible");
//     player.setJob("Warrior");
//     string name = "Dragon";
//     std::unique_ptr<Card> card = Card::createCard(name); 
//     card->applyCard(player);
//     name = "PotionsMerchant";
//     player.addCoins(20);
//     std::unique_ptr<Card> card2 = Card::createCard(name); 
//     card2->applyCard(player);
//     return 0;
// }