#ifndef EX4_Job_H
#define EX4_Job_H
#include "Player.h"
class Player;

class Job {
public:
    Job(const string& jobName) : m_jobName(jobName) {};
    virtual ~Job() = default;
    Job(const Job&) = default;
    Job& operator=(const Job&) = default;
    virtual int getPower(const Player& player) const;
    virtual void handleEvent(Player& player, string& result) const;
    const string& getName() const;
private:
    string m_jobName;
};

class Warrior : public Job {
public:
    Warrior() : Job(NAME) {};
    ~Warrior() = default;
    Warrior(const Warrior&) = default;
    Warrior& operator=(const Warrior&) = default;
    int getPower(const Player& player) const override;
private:
    static const string NAME;
};

class Sorcerer : public Job {
public:
    Sorcerer() : Job(NAME) {};
    ~Sorcerer() = default;
    Sorcerer(const Sorcerer&) = default;
    Sorcerer& operator=(const Sorcerer&) = default;
    void handleEvent(Player& playe, string& result) const override;
private:
    static const string NAME;
};


#endif //EX4_Job_H