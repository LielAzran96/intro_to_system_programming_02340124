#include "Events.h"
#include "../Players/Player.h"
#include "../Players/Behavior.h"
#include "../Players/Job.h"


/*Event Scenario - SolarEclipse*/
string SolarEclipse::applyCard(Player& player) const {
    string result; 
    player.handleSolarEclipse(result);
    return result;
}

/*Event Scenario - PotionsMerchant*/
string PotionsMerchant::applyCard(Player& player) const {
    string result; 
    player.handlePotionsMerchant(result);
    return result;
}

