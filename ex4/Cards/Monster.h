#ifndef EX4_Monster_H
#define EX4_Monster_H

#include "Card.h"
#include <map>

class Monster : public Card {
public:
    /**
     * Constructor for Monster card.
     * 
     * @param name - The name of the monster.
     */
    Monster(const std::string& name);

    /**
     * Default constructor for Monster card - created for the "Gang" case.
     */
    Monster() : Card(""), m_power(0), m_loot(0), m_damage(0) {};
    virtual ~Monster() = default;
    Monster(const Monster&) = default;
    Monster& operator=(const Monster&) = default;

    /*Static constant representing the monster map*/
    static const std::map<std::string, std::map<std::string, int>> MONSTER_MAP;

    /**
     * Applies the effect of the Monster card on a player.
     * 
     * @param player - The player to apply the card's effect on.
     * @return - A message indicating the result of applying the card.
     */
    std::string applyCard(Player& player) const override;

    /**
     * Gets the description of the Monster card.
     * 
     * @return - The description of the Monster card.
     */
    virtual std::string getDescription() const override;

protected:
    int m_power;    
    int m_loot;     
    int m_damage;   
};

class Gang : public Monster {
public:
    /**
     * Default constructor for Gang card.
     */
    Gang() : Monster(), m_numberOfMonsters(0) {};

    // Destructor
    ~Gang() = default;
    Gang(const Gang&) = delete;
    Gang& operator=(const Gang&) = delete;

    /**
     * Adds a monster to the gang.
     * note - we dont add the monster itself, but it's values
     * 
     * @param name - The name of the monster that it's params needs to be added.
     */
    void addMonster(const std::string& name);

    /**
     * Sets the number of monsters in the gang.
     * 
     * @param number - The number of monsters in the gang.
     */
    void setMonstersNumber(int number);

    /**
     * Gets the description of the Gang card.
     * 
     * @return - The description of the Gang card.
     */
    std::string getDescription() const override;

    /**
     * Exception class for when a monster is not found in the gang.
     */
    class MonsterNotFound : std::exception {};

protected:
    int m_numberOfMonsters;    
};

#endif //EX4_Monster_H