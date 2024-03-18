
#pragma once

#include <string>
#include "HealthPoints.h"
#include <memory>
class Job;
class Behavior;

using std::string;
using std::unique_ptr;

class Player {
public:
    /**
     * C'tor of Payer class
     *
     * @param name - The name of the player.
     * @param job - The job of the player.
     * @param behavior - The behavior of the player.
     * dd
     * @return
     *      A new instance of Player.
    */
    explicit Player(const string name);
    ~Player() = default;
    /**
     * Gets the description of the player
     * 
     * @return - description of the player
    */
    string getDescription() const;

    /**
     * Gets the name of the player
     * 
     * @return - name of the player
    */
    string getName() const;

    /**
     * Gets the current level of the player
     * 
     * @return - level of the player
    */
    int getLevel() const;

    /**
     * Gets the of force the player has
     * 
     * @return - force points of the player
    */
    int getForce() const;

    /**
     * Gets the amount of health points the player currently has
     * 
     * @return - health points of the player
    */
    int getHealthPoints() const;

    int getMaxHp() const;
    /**
     * Gets the amount of coins the player has
     * 
     * @return - coins of the player
    */
    int getCoins() const;

    /** levelUp - raises the player's level in 1 level up.
     the max level is 10 - so when a player is in level 10, nothing will be changed*/
    void levelUp();

    /** updateForce - raises/decreases the force in an amount recieved by the user
     * @param forceToUpdate - the amount of force that needs to be added/remove to the player's current force.
     * minimal force is zero
     * @return - true if the force updates, false if not
    */
    bool updateForce(const int forceToUpdate);

    /** heal - raises the hp in an amount recieved by the user, until maxHP
     * @param hpToAdd - the amount of hp that needs to be added to the player's current hp. 
     * the hp can be raised until maximum hp of the player
    */
    void heal(const int hpToAdd);

     /** damageHP - reduces the health points in an amount recieved by the user, until hp reaches to zero.
     * @param hpToRemove - the amount of HP that needs to be removed from the player's current hp.
     * the hp can be removed until hp=0.
    */
    void damageHP(const int hpToRemove);

    /** isKnockedOut - checkes if the player's HP is reached to zero
     * @return - 
     *      true - if the HP is 0.
     *      false - if the HP is not 0.
    */
    bool isKnockedOut() const;

    /** addCoins - add coins to the player's current coins
     * @param coinsToAdd - the amount of coins that needs to be added to the player's current coins.
    */
    void addCoins(const int coinsToAdd);

    /** pay - pay coins
     * @param coinsToPay - the amount of coins that needs to be payed and removed from the the player's current coins.
     * @return -
     *      true - if the payment succeeded
     *      false - if the payment fails (and no change is being made to the current player's coins)
    */
    bool pay(const int coinsToPay);

    /** getCombatPower - returns the combat power strength of the player. 
     * the default combat power is defined as the force + level.
     * for warriors its force*2 + level.
     * 
     * @return - the amount of attack strength computed inside the member function.
    */
    int getCombatPower() const;

    void setBehavior(const string& behaviorName);
    const Behavior& getBehavior() const;

    void setJob(const string& jobName);
    const Job& getJob() const;
private:
    string m_name;
    int m_level;
    int m_force;
    HealthPoints m_hp;
    int m_coins;
    unique_ptr<Job> m_job;
    unique_ptr<Behavior> m_behavior;
    friend bool operator<(const Player& player1, const Player& player2);

     /** the initial and default variables of the class Player*/
    static const int INITIAL_LEVEL = 1;
    static const int FINAL_LEVEL; 
    static const int INITIAL_COINS = 10;
    static const int DEFAULT_FORCE = 5;

};
