#ifndef EX4_Behavior_H
#define EX4_Behavior_H
#include <string>
using std::string;
class Player;

class Behavior {
public:
    Behavior(const string& behaviorName) : m_behaviorName(behaviorName) {};
    virtual ~Behavior() = default;
    Behavior(const Behavior&) = default;
    Behavior& operator=(const Behavior&) = default;
    virtual void handleEvent(Player& player, string& result) const = 0; 
    const string& getName() const;
protected:
    string m_behaviorName;
};

class ResponsibleBehavior : public Behavior {
public:
    ResponsibleBehavior() : Behavior(NAME) {};
    ~ResponsibleBehavior() = default;
    ResponsibleBehavior(const ResponsibleBehavior&) = default;
    ResponsibleBehavior& operator=(const ResponsibleBehavior&) = default;
    void handleEvent(Player& player, string& result) const override;
private:
    static const string NAME;
};

class RiskTakingBehavior : public Behavior {
public:
    RiskTakingBehavior() : Behavior(NAME) {};
    ~RiskTakingBehavior() = default;
    RiskTakingBehavior(const RiskTakingBehavior&) = default;
    RiskTakingBehavior& operator=(const RiskTakingBehavior&) = default;
    void handleEvent(Player& player, string& result) const override;
private:
    static const string NAME;
};

#endif //EX4_Behavior_H