#ifndef EX4_Card_H
#define EX4_Card_H

#include <string>
#include <vector>

using std::string; 
class Player;

class Card {
public:
    /**
     * Constructor for Card class.
     * 
     * @param name - The name of the card.
     */
    Card(const std::string& name) : m_cardName(name) {};

    Card(const Card&) = default;
    Card& operator=(const Card&) = default;

    /**
     * Virtual function to get the description of the card.
     * 
     * @return - The description of the card.
     */
    virtual std::string getDescription() const;

    /**
     * Virtual function to apply the effect of the card on a player.
     * 
     * @param player - The player to apply the card's effect on.
     * @return - A message indicating the result of applying the card.
     */
    virtual std::string applyCard(Player& player) const = 0;

    virtual ~Card() = default;

    /*Static vector containing event names*/
    static const std::vector<std::string> EVENTS_VECTOR;

protected:
    std::string m_cardName; 
};

#endif //EX4_Card_H