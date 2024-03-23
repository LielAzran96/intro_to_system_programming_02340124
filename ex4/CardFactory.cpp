#include "CardFactory.h"
#include <fstream>
#include "Cards/Events.h"
#include "Cards/Monster.h"
#include "Cards/Card.h"
using std::string;
using std::unique_ptr;

/**
 * handleGang function - deals with  adding the params of the gang's members to the existing ones. 
 * recursive function - deals with nested gangs as well
 *
 * @param cardsFile - the file from which we read the cards.
 * @param numberOfMonsters - the number of the monsters in the gang.
 */
static void handleGang(std::ifstream& cardsFile,Gang& gang ,int numberOfMonsters) {
    string word;
    int numberOfMonstersNestedGang = 0;
    while((cardsFile >> word)) {
        if(word == "Gang") {
            if((cardsFile >> numberOfMonstersNestedGang) && numberOfMonstersNestedGang > 1) {
                handleGang(cardsFile, gang, numberOfMonstersNestedGang);
            }
            else {
                throw std::runtime_error("Invalid Cards File");
            }
        }
        else {
            try {
                gang.addMonster(word);
            }
            catch(const Gang::MonsterNotFound&) {
                throw std::runtime_error("Invalid Cards File");
            }
        }
        numberOfMonsters--;
        if(numberOfMonsters == 0) {
            break;
        }
    }
    if(numberOfMonsters != 0) {
        throw std::runtime_error("Invalid Cards File");
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
    if((cardsFile >> numberOfMonstersInFile) && numberOfMonstersInFile > 1)  {
        gang->setMonstersNumber(numberOfMonstersInFile);
        handleGang(cardsFile, *gang, numberOfMonstersInFile);
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
        return unique_ptr<Card>(new Monster(cardName));
    }
    else if(cardName == "Gang") {
        return createGang(cardsFile);
    }
  throw std::runtime_error("Invalid Cards File");
}



