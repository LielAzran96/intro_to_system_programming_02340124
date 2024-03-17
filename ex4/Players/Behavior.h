#ifndef EX4_Behavior_H
#define EX4_Behavior_H
#include <string>
using std::string;
class Player;

class Behavior {
public:
    Behavior(const string& behaviorName) : m_behaviorName(behaviorName) {};
    virtual void handleEvent(Player& player, string& result) const = 0; 
    virtual ~Behavior() = default;
    const string& getName() const;
protected:
    string m_behaviorName;
};

class ResponsibleBehavior : public Behavior {
public:
    ResponsibleBehavior() : Behavior(NAME) {};
    void handleEvent(Player& player, string& result) const override;
private:
    static const string NAME;
};

class RiskTakerBehavior : public Behavior {
public:
    RiskTakerBehavior() : Behavior(NAME) {};
    void handleEvent(Player& player, string& result) const override;
private:
    static const string NAME;
};

#endif //EX4_Behavior_H