#ifndef EX4_Job_H
#define EX4_Job_H
#include <vector>
#include <string>
class Player;

class Job {
public:
    Job(const std::string& jobName) : m_jobName(jobName) {};
    virtual ~Job() = default;
    Job(const Job&) = default;
    Job& operator=(const Job&) = default;
    virtual int getPower(const Player& player) const;
    virtual void handleEvent(Player& player, std::string& result) const;
    virtual bool handleBattle(Player& player, int monsterPower, int monsterLoot, int monsterDamage) const;
    const std::string& getName() const;
    static const std::vector<std::string> JOB_VECTOR;
private:
    std::string m_jobName;
};

class Warrior : public Job {
public:
    Warrior() : Job(JOB_VECTOR[0]) {};
    ~Warrior() = default;
    Warrior(const Warrior&) = default;
    Warrior& operator=(const Warrior&) = default;
    int getPower(const Player& player) const override;
};

class Sorcerer : public Job {
public:
    Sorcerer() : Job(JOB_VECTOR[1]) {};
    ~Sorcerer() = default;
    Sorcerer(const Sorcerer&) = default;
    Sorcerer& operator=(const Sorcerer&) = default;
    void handleEvent(Player& playe, std::string& result) const override;
};


#endif //EX4_Job_H