#include "Behavior.h"
#include "Player.h"
#include "../Cards/Events.h"
#include <memory>
#include "utilities.h"
#include <algorithm>

const vector<string> Behavior::BEHAVIOR_VECTOR = {"Responsible", "RiskTaking"};

Behavior::Behavior(const string& behaviorName) : m_behaviorName(behaviorName) {};

const string& Behavior::getName() const {
    return m_behaviorName;
}

ResponsibleBehavior::ResponsibleBehavior() : Behavior(BEHAVIOR_VECTOR[0]) {};

int ResponsibleBehavior::handlePotionsMerchant(const Player& player) const {
    int amountOfPotionsByMoney = static_cast<int> (player.getCoins()/PotionsMerchant::POTION_COST);
    int amountOfPotionsByHP = static_cast<int>((player.getMaxHp() - player.getHealthPoints()) / PotionsMerchant::HP_TO_GIVE);
    if(amountOfPotionsByMoney >= 1) {
        /*return the minimum amount of potions a player can buy based on his current coins and HP*/
        return std::min(amountOfPotionsByMoney, amountOfPotionsByHP);
    }
    else {
        return 0;
    }
}


RiskTakingBehavior::RiskTakingBehavior() : Behavior(BEHAVIOR_VECTOR[1]) {};

int RiskTakingBehavior::handlePotionsMerchant(const Player& player) const {
    if((player.getHealthPoints()) < 50 && (player.getCoins() >= PotionsMerchant::POTION_COST)) {
        return 1;
    }
    else {
        return 0;
    }
}
