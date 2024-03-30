#include "Events.h"
#include "../Players/Player.h"
#include "../Players/Behavior.h"
#include "../Players/Job.h"
#include "utilities.h"

/*Event Scenario - SolarEclipse*/
string SolarEclipse::applyCard(Player& player) const {
    string result; 
    int sign = player.getJob().handleSolarEclipse();
    if(player.updateForce(sign*SolarEclipse::FORCE_TO_UPDATE)){
        result = getSolarEclipseMessage(player, sign*SolarEclipse::FORCE_TO_UPDATE);
    } 
    else {
        result = getSolarEclipseMessage(player, 0);
    }
    return result;
}

/*Event Scenario - PotionsMerchant*/
string PotionsMerchant::applyCard(Player& player) const {
    int amountOfPotions = player.getBehavior().handlePotionsMerchant(player);
    for(int i = 0; i < amountOfPotions; i++) {
        player.pay(PotionsMerchant::POTION_COST); 
        player.heal(PotionsMerchant::HP_TO_GIVE);
    }
    return getPotionsPurchaseMessage(player, amountOfPotions);
}


