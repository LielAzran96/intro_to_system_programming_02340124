#ifndef EX4_Behavior_H
#define EX4_Behavior_H

#include <string>
#include <vector>
using std::string;
using std::vector;

class Player;

class Behavior {
public:
    /**
     * Constructor for the Behavior class.
     *
     * @param behaviorName - The name of the behavior.
     */
    Behavior(const string& behaviorName);

    /**
     * Virtual destructor for the Behavior class.
     */
    virtual ~Behavior() = default;

    /**
     * Copy constructor for the Behavior class.
     */
    Behavior(const Behavior&) = default;

    /**
     * Copy assignment operator for the Behavior class.
     */
    Behavior& operator=(const Behavior&) = default;

    /**
     * Virtual method to handle the PotionsMerchant event for a player with this behavior.
     *
     * @param player - The player to handle the event for.
     * @return 
     *     the number of potions a player can buy.
     */
    virtual int handlePotionsMerchant(const Player& player) const = 0; 

    /**
     * Getter for the name of the behavior.
     *
     * @return The name of the behavior.
     */
    const string& getName() const;

    /**
     * Static vector containing behavior names.
     */
    static const vector<string> BEHAVIOR_VECTOR;

protected:
    string m_behaviorName;
};

class ResponsibleBehavior : public Behavior {
public:
    ResponsibleBehavior();
    ~ResponsibleBehavior() = default;
    /**
     * Copy c'tor & assignment operator deleted.
     */
    ResponsibleBehavior(const ResponsibleBehavior&) = delete;
    ResponsibleBehavior& operator=(const ResponsibleBehavior&) = delete;

    /* Override method to handle the PotionsMerchant event for a player with this behavior
    a responsible player will buy as many potions he can, until he runs out of coins or his hp is maximal*/
    int handlePotionsMerchant(const Player& player) const override;
};

class RiskTakingBehavior : public Behavior {
public:
 
    RiskTakingBehavior();
    ~RiskTakingBehavior() = default;
    /**
     * Copy c'tor & assignment operator deleted 
     */
    RiskTakingBehavior(const RiskTakingBehavior&) = delete;
    RiskTakingBehavior& operator=(const RiskTakingBehavior&) = delete;

    /* Override method to handle the PotionsMerchant event for a player with this behavior
    a riskTaking player will buy up to one potion, only if his hp below 50 points*/
    int handlePotionsMerchant(const Player& player) const override;
};

#endif //EX4_Behavior_H