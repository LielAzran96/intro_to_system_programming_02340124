#include "Behavior.h"
#include "Player.h"
#include "../Cards/Card.h"
#include <memory>
#include "../utilities.h"

const string& Behavior::getName() const {
    return m_behaviorName;
}

const string ResponsibleBehavior::NAME = "Responsible";

void ResponsibleBehavior::handleEvent(Player& player, string& result) const {
    int amountOfPotions = 0;
     while((player.getCoins() != 0) && (player.getHealthPoints() != player.getMaxHp())) {
        player.pay(PotionsMerchant::POTION_COST); 
        player.heal(PotionsMerchant::HP_TO_GIVE);
        amountOfPotions++;
    }
    result = getPotionsPurchaseMessage(player, amountOfPotions);
}

const string RiskTakingBehavior::NAME = "RiskTaking";

void RiskTakingBehavior::handleEvent(Player& player, string& result) const {
    int amountOfPotions = 0;
    if(player.getHealthPoints() < 50) {
        player.pay(PotionsMerchant::POTION_COST); 
        player.heal(PotionsMerchant::HP_TO_GIVE); 
    }
    result = getPotionsPurchaseMessage(player, amountOfPotions);
}
