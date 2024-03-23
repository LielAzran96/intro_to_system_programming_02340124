#pragma once

#include <string>
#include "HealthPoints.h"
#include <memory>
#include "Job.h"
#include "Behavior.h"

class Player {
public:
    /**
     * Constructor of Player class.
     *
     * @param name - The name of the player.
     * @return A new instance of Player.
    */
    explicit Player(const std::string name);

    /**
     * Destructor of Player class.
    */
    ~Player() = default;
    /*delete the option to copy \ assign one player to another*/
    Player& operator=(const Player& ) = delete;
    Player(const Player& ) = delete;

    /**
     * Gets the description of the player.
     * 
     * @return Description of the player.
    */
    std::string getDescription() const;

    /**
     * Gets the name of the player.
     * 
     * @return Name of the player.
    */
    std::string getName() const;

    /**
     * Gets the current level of the player.
     * 
     * @return Level of the player.
    */
    int getLevel() const;

    /**
     * Gets the force points of the player.
     * 
     * @return Force points of the player.
    */
    int getForce() const;

    /**
     * Gets the amount of health points the player currently has.
     * 
     * @return Health points of the player.
    */
    int getHealthPoints() const;

    /**
     * Gets the maximum health points of the player.
     * 
     * @return Maximum health points of the player.
    */
    int getMaxHp() const;

    /**
     * Gets the amount of coins the player has.
     * 
     * @return Coins of the player.
    */
    int getCoins() const;

    /**
     * Increases the player's level by 1.
     * The maximum level is 10.
    */
    void levelUp();

    /**
     * Updates the player's force by adding or subtracting a specified amount.
     * 
     * @param forceToUpdate The amount of force to update.
     * @return True if the force updates, false otherwise.
    */
    bool updateForce(const int forceToUpdate);

    /**
     * Increases the player's health points by a specified amount, up to the maximum HP.
     * 
     * @param hpToAdd The amount of HP to add.
    */
    void heal(const int hpToAdd);

    /**
     * Reduces the player's health points by a specified amount.
     * 
     * @param hpToRemove The amount of HP to remove.
    */
    void damageHP(const int hpToRemove);

    /**
     * Checks if the player's HP is zero.
     * 
     * @return True if HP is 0, false otherwise.
    */
    bool isKnockedOut() const;

    /**
     * Adds coins to the player's current coins.
     * 
     * @param coinsToAdd The amount of coins to add.
    */
    void addCoins(const int coinsToAdd);

    /**
     * Pays coins and subtracts them from the player's current coins.
     * 
     * @param coinsToPay The amount of coins to pay.
     * @return True if the payment succeeded, false otherwise.
    */
    bool pay(const int coinsToPay);

    /**
     * Computes and returns the combat power strength of the player.
     * for a regular player - force + level. for a warrior - 2*force + level
     * @return Combat power strength.
    */
    int getCombatPower() const;

    /**
     * Sets the behavior of the player.
     * 
     * @param behavior The behavior of the player.
    */
    void setBehavior(const std::unique_ptr<Behavior> behavior);

    /**
     * Gets the behavior of the player.
     * 
     * @return Reference to the player's behavior.
    */
    const Behavior& getBehavior() const;

    /**
     * Sets the job of the player.
     * 
     * @param job The job of the player.
    */
    void setJob(std::unique_ptr<Job> job);

    /**
     * Gets the job of the player.
     * 
     * @return Reference to the player's job.
    */
    const Job& getJob() const;

    /**
     * Handles the effects of a Solar Eclipse event.
     * 
     * @param result - string that contains how many force the player lost\recieve.
    */
    void handleSolarEclipse(std::string& result); 

    /**
     * Handles the effects of a Potions Merchant event.
     * 
     * @param result - string that containts how many potions the player bought
    */
    void handlePotionsMerchant(std::string& result); 

    /**
     * Handles the battle with a monster.
     * 
     * @param monsterPower Power of the monster.
     * @param monsterLoot Loot of the monster.
     * @param monsterDamage Damage of the monster.
     * @return True if the battle is successful, false otherwise.
    */
    bool handleBattle(int monsterPower, int monsterLoot, int monsterDamage); 

private:
    std::string m_name;
    int m_level;
    int m_force;
    HealthPoints m_hp;
    int m_coins;
    std::unique_ptr<Job> m_job;
    std::unique_ptr<Behavior> m_behavior;

    friend bool operator<(const Player& player1, const Player& player2);
    static const int INITIAL_LEVEL = 1;
    static const int FINAL_LEVEL; 
    static const int INITIAL_COINS = 10;
    static const int DEFAULT_FORCE = 5;
};
