#ifndef EX4_Job_H
#define EX4_Job_H

#include <vector>
#include <string>
class Player;

class Job {
public:
    /**
     * Constructor for the Job class.
     *
     * @param jobName - The name of the job.
     */
    Job(const std::string& jobName);

    /**
     * Virtual destructor for the Job class.
     */
    virtual ~Job() = default;

    /**
     * Copy constructor for the Job class.
     */
    Job(const Job&) = default;

    /**
     * Copy assignment operator for the Job class.
     */
    Job& operator=(const Job&) = default;

    /**
     * Virtual method to get the combat power of the player based on their job.
     *
     * @param player - The player whose power needs to be determined.
     * @return 
     *        The combat power of the player.
     */
    virtual int getPower(const Player& player) const;

    /**
     * Virtual method to handle the SolarEclipse event for a player with this job.
     *
     * @return
     *       The sign of the force needed to be update on this event based on the player's job.
     */
    virtual int handleSolarEclipse() const;

    /**
     * Virtual method to handle a battle between the player and a monster.
     *
     * @param player - The player involved in the battle.
     * @param monsterPower - The power of the monster in the battle.
     * @return
     *       true if the player wins the battle based on his combat power, false otherwise.
     */
    virtual bool handleBattle(Player& player, int monsterPower) const;

    /**
     * Getter for the name of the job.
     *
     * @return The name of the job.
     */
    const std::string& getName() const;

    /**
     * Static vector containing job names.
     */
    static const std::vector<std::string> JOB_VECTOR;
private:
    std::string m_jobName;
};

class Warrior : public Job {
public:
    Warrior();
    ~Warrior() = default;

    /**
     * Copy c'tor & assignment operator deleted.
     */
    Warrior(const Warrior&) = delete;
    Warrior& operator=(const Warrior&) = delete;

    /* Override method to get the power of the player based on their job as a warrior*/
    int getPower(const Player& player) const override;
};

class Sorcerer : public Job {
public:
    Sorcerer();
    ~Sorcerer() = default;

    /**
     * Copy c'tor & assignment operator deleted.
     */
    Sorcerer(const Sorcerer&) = delete;
    Sorcerer& operator=(const Sorcerer&) = delete;
    
    /* Override method to handle the SolarEclipse event for a player with this job as a sorcerer*/
    int handleSolarEclipse() const override;
};

#endif //EX4_Job_H