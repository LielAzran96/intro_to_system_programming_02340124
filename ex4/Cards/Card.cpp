#include "Card.h"

const std::vector<std::string> Card::EVENTS_VECTOR = {"SolarEclipse", "PotionsMerchant"};

string Card::getDescription() const {
    return m_cardName;
}





