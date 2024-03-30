#ifndef EX4_CardFactory_H
#define EX4_CardFactory_H

#include <memory>
#include "Cards/Card.h"
#include <map>
#include <stdexcept> 

class CardFactory {
public:
    /**
     * C'tor of CardFactory class
     *
     * @return
     *      A new instance of CardFactory.
     */
    explicit CardFactory() = default;

    /*
    * copy C'tor of the factory:
    *deleted
    */
    CardFactory(const CardFactory&) = delete;

    /*
      * Assignment C'tor of the factory:
      *deleted
      */
    CardFactory& operator=(const CardFactory&) = delete;

    /**
    * D'tor of the class: default
    */
    ~CardFactory() = default;

    /**
     * Create Card function
     *
     * @param cardsFile - the file from which we read the cards.
     * @param cardName - the name of the card.
     * @return
     *     std::unique_ptr<Card> of the new instance of Card.
     */
    std::unique_ptr<Card> create(std::ifstream& cardsFile, const std::string& cardName) const;

       /*Static constant representing the monster map*/
    static const std::map<std::string, std::map<std::string, int>> MONSTER_MAP;
 
};

#endif //EX4_CardFactory_H