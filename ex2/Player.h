#ifndef EX2_Player_H
#define EX2_Player_H

#include <cstring>
#include "utilities.h"

class Player {
public:
    /**
     * C'tor of Payer class
     *
     * @param name - The name of the player.
     * @param maxHp - The naximal health point.
     * @param force - The initial force of the player.
     * @return
     *      A new instance of Player.
    */
    Player(const char* name = "Efrat", const int maxHp = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);

    /** Copy c'tor, destructor, and assignment operator of class Payer*/
    Player(const Player& otherPlayer);
    ~Player();
    Player& operator=(const Player& otherPlayer);

    /** printInfo - prints the player's info*/
    void printInfo() const;

    /** levelUp - raises the player's level in 1 level up.
     the max level is 10 - so when a player is in level 10, nothing will be changed*/
    void levelUp();

    /** getLevel - 
    * @return - the player's current level*/
    int getLevel() const;

    /** buff - raises the force in an amount recieved by the user
     * @param forceToAdd - the amount of force that needs to be added to the player's current force.
    */
    void buff(int forceToAdd);

    /** heal - raises the force in an amount recieved by the user
     * @param forceToAdd - the amount of force that needs to be added to the player's current force.
    */
    void heal(int hpToAdd);

     /** damage - reduces the health points in an amount recieved by the user
     * @param hpToRemove - the amount of HP that needs to be removed from the player's current force.
    */
    void damage(int hpToRemove);

    /** isKnockedOut - checkes if the player's HP is reached to zero
     * @return - 
     *      true - if the HP is 0.
     *      false - if the HP is not 0.
    */
    bool isKnockedOut() const;

    /** addCoins - add coins to the player's current coins
     * @param coinsToAdd - the amount of coins that needs to be added to the player's current coins.
    */
    void addCoins(int coinsToAdd);

    /** pay - pay coins
     * @param coinsToPay - the amount of coins that needs to be payed and removed from the the player's current coins.
     * @return -
     *      true - if the payment succeeded
     *      false - if the payment fails (and no change is being made to the current player's coins)
    */
    bool pay(int coinsToPay);

    /** getAttackStrength - returns the attack strength of the player. 
     * the attack strength is defined as the force+level.
     * 
     * @return - the amount of attack strength computed inside the member function.
    */
    int getAttackStrength() const;



private:
    char* m_name;
    int m_level;
    int m_force;
    int m_maxHp;
    int m_hp;
    int m_coins;

    /** the initial and default variables of the class Player*/
    static const int INITIAL_LEVEL = 1;
    static const int FINAL_LEVEL = 10;
    static const int INITIAL_COINS = 0;
    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_FORCE = 5;
};



#endif //EX2_Player_H