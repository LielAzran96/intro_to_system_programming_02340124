#include "BehaviorFactory.h"

unique_ptr<Behavior> BehaviorFactory::create(const string& behaviorName) {
    if(behaviorName == "Responsible") {
        return unique_ptr<ResponsibleBehavior>(new ResponsibleBehavior());
    }
    else if(behaviorName == "RiskTaking") {
        return unique_ptr<RiskTakingBehavior>(new RiskTakingBehavior());
    }
    else {
        throw std::runtime_error("Invalid Players File"); 
    }
}