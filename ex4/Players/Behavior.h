#ifndef EX4_Behavior_H
#define EX4_Behavior_H
#include <string>
using std::string;
#include <vector>
using std::vector;
class Player;

class Behavior {
public:
    Behavior(const string& behaviorName) : m_behaviorName(behaviorName) {};
    virtual ~Behavior() = default;
    Behavior(const Behavior&) = default;
    Behavior& operator=(const Behavior&) = default;
    virtual void handleEvent(Player& player, string& result) const = 0; 
    const string& getName() const;
    static const vector<string> BEHAVIOR_VECTOR;
protected:
    string m_behaviorName;
};

class ResponsibleBehavior : public Behavior {
public:
    ResponsibleBehavior() : Behavior(BEHAVIOR_VECTOR[0]) {};
    ~ResponsibleBehavior() = default;
    ResponsibleBehavior(const ResponsibleBehavior&) = default;
    ResponsibleBehavior& operator=(const ResponsibleBehavior&) = default;
    void handleEvent(Player& player, string& result) const override;
};

class RiskTakingBehavior : public Behavior {
public:
    RiskTakingBehavior() : Behavior(BEHAVIOR_VECTOR[1]) {};
    ~RiskTakingBehavior() = default;
    RiskTakingBehavior(const RiskTakingBehavior&) = default;
    RiskTakingBehavior& operator=(const RiskTakingBehavior&) = default;
    void handleEvent(Player& player, string& result) const override;

};

#endif //EX4_Behavior_H