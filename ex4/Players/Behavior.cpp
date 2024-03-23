#include "Behavior.h"
#include "Player.h"
#include "../Cards/Events.h"
#include <memory>
#include "../utilities.h"

const vector<string> Behavior::BEHAVIOR_VECTOR = {"Responsible", "RiskTaking"};

const string& Behavior::getName() const {
    return m_behaviorName;
}

void ResponsibleBehavior::handleEvent(Player& player, string& result) const {
    int amountOfPotions = 0;
     while((player.getCoins() >= PotionsMerchant::POTION_COST) && (player.getHealthPoints() != player.getMaxHp())) {
        player.pay(PotionsMerchant::POTION_COST); 
        player.heal(PotionsMerchant::HP_TO_GIVE);
        amountOfPotions++;
    }
    result = getPotionsPurchaseMessage(player, amountOfPotions);
}

void RiskTakingBehavior::handleEvent(Player& player, string& result) const {
    int amountOfPotions = 0;
    if((player.getHealthPoints() < 50) && (player.getCoins() >= PotionsMerchant::POTION_COST)) {
        player.pay(PotionsMerchant::POTION_COST); 
        player.heal(PotionsMerchant::HP_TO_GIVE); 
        amountOfPotions++;
    }
    result = getPotionsPurchaseMessage(player, amountOfPotions);
}
