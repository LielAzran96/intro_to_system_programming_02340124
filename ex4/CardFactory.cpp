#include "CardFactory.h"
#include <fstream>
#include "Cards/Events.h"
#include "Cards/Monster.h"
#include "Cards/Card.h"
using std::string;
using std::unique_ptr;
using std::map;

const std::map<std::string, std::map<string, int>> CardFactory::MONSTER_MAP = {
    {"Goblin", {{"power", 5}, {"loot", 2}, {"damage", 10}}},
    {"Giant", {{"power", 12}, {"loot", 5}, {"damage", 25}}},
    {"Dragon", {{"power", 17}, {"loot", 100}, {"damage", 9001}}},
};


/**
 * createMonster function - deals with creating a monster instance 
 *
 * @param monsterName - the name of the monster.
 * @return 
 *      new intance of a Monster.
 */
static Monster createMonster(const string& monsterName) {
    auto it = CardFactory::MONSTER_MAP.find(monsterName);
    if(it != CardFactory::MONSTER_MAP.end()) {
        return Monster(monsterName, it->second.at("power"), it->second.at("loot"), it->second.at("damage"));
    }
    else {
        throw std::runtime_error("Invalid Cards File");
    }
}

/**
 * handleGang function - deals with  adding the params of the gang's members to the existing ones. 
 * recursive function - deals with nested gangs as well
 *
 * @param cardsFile - the file from which we read the cards.
 * @param gang - the gang that needs to be updated
 * @param numberOfMonsters - the number of the monsters in the gang.
 * 
 */
static void handleGang(std::ifstream& cardsFile, Gang& gang ,int numberOfMonsters) {
    string word;
    int numberOfMonstersNestedGang = 0;
    for(int i = 0; i < numberOfMonsters; i++) {
        if(!(cardsFile >> std::ws >> word)) {
            throw std::runtime_error("Invalid Cards File");
        } 
        if(word == "Gang") {
            if((cardsFile >> std::ws >>  numberOfMonstersNestedGang) && numberOfMonstersNestedGang > 1) {
                Gang NestedGang;
                handleGang(cardsFile, NestedGang, numberOfMonstersNestedGang);
                gang.addMonster(NestedGang);
            }
            else {
                throw std::runtime_error("Invalid Cards File");
            }
        }
        else {
            gang.addMonster(createMonster(word));
        }
    }
}

/**
 * createGang function - deals with creating a gang card
 *
 * @param cardsFile - the file from which we read the cards.
 * @return 
 *      std::unique_ptr<Card> of the new instance of Card.
 */
static unique_ptr<Card> createGang(std::ifstream& cardsFile) {
    int numberOfMonstersInFile = 0;
    unique_ptr<Gang> gang(new Gang());
    if((cardsFile >> std::ws >> numberOfMonstersInFile) && numberOfMonstersInFile > 1)  {
        handleGang(cardsFile, *gang, numberOfMonstersInFile);
        gang->setGangName();
    }
    else {
        throw std::runtime_error("Invalid Cards File");
    }
    return std::unique_ptr<Card>(std::move(gang));
}

unique_ptr<Card> CardFactory::create(std::ifstream& cardsFile, const string& cardName) const {
    if(cardName == "SolarEclipse") {
        return unique_ptr<Card>(new SolarEclipse());
    }
    else if(cardName == "PotionsMerchant") {
        return unique_ptr<Card>(new PotionsMerchant());
    }
    else if(cardName == "Goblin" || cardName == "Dragon" || cardName == "Giant") {
        return unique_ptr<Card>(new Monster(createMonster(cardName)));
    }
    else if(cardName == "Gang") {
        return createGang(cardsFile);
    }
  throw std::runtime_error("Invalid Cards File");
}

