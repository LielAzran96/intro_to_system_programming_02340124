#ifndef EX4_Monster_H
#define EX4_Monster_H

#include "Card.h"

class Monster : public Card {
public:
    /**
     * Constructor for Monster card.
     * 
     * @param name - The name of the monster.
     * @param power - the power of the monster.
     * @param loot - the loot given when winning the monster.
     * @param damage - the damage getting when loosing the monster.
     * 
     * @return
     *      A new instance of Monster Card.
     */
    Monster(const string& name, int power, int loot, int damage);

    /**
     * Default constructor for Monster card - created for the "Gang" case.
     */
    Monster() : Card(""), m_power(0), m_loot(0), m_damage(0) {};
    virtual ~Monster() = default;
    Monster(const Monster&) = default;
    Monster& operator=(const Monster&) = default;

  

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
    std::string getDescription() const override;
    int getPower() const;
    int getLoot() const;
    int getDamage() const;

protected:
    int m_power;    
    int m_loot;     
    int m_damage;   
};

class Gang : public Monster {
public:
    /**
     * Constructor for Gang card.
     */
    Gang();

    // Destructor
    ~Gang() = default;
    Gang(const Gang&) = default;
    Gang& operator=(const Gang&) = default;

    /**
     * Adds a monster to the gang.
     * note - we dont add the monster itself, but it's values
     * 
     * @param monster - The monster that it's params needs to be added.
     */
    void addMonster(const Monster& monster);

   /**
     * Gets the number of monsters in the gang. in case of gang as - "Gang of <numberOfMonsters> members" 
     * @return
     *       the number of monsters in the gang.
    */
    int getNumberOfMonsters() const;

    /**
     * Sets the card's name as - "Gang of <m_numberOfMonsters> members".
    */ 
    void setGangName(); 

private:
    int m_numberOfMonsters;
};

#endif //EX4_Monster_H