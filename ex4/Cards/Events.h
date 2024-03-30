#ifndef EX4_Events_H
#define EX4_Events_H

#include "Card.h"


class SolarEclipse : public Card {
public:
    /**
     * Constructor for SolarEclipse card.
     */
    SolarEclipse() : Card(EVENTS_VECTOR[0]) {};
    ~SolarEclipse() = default;
    SolarEclipse(const SolarEclipse&) = default;
    SolarEclipse& operator=(const SolarEclipse&) = default;

    /**
     * Applies the effect of the SolarEclipse card on a player.
     * 
     * @param player - The player to apply the card's effect on.
     * @return - A message indicating the result of applying the card.
     */
    std::string applyCard(Player& player) const override;

    static const int FORCE_TO_UPDATE = 1;
};

class PotionsMerchant : public Card {
public:
    /**
     * Constructor for PotionsMerchant card.
     */
    PotionsMerchant() : Card(EVENTS_VECTOR[1]) {};
    ~PotionsMerchant() = default;
    PotionsMerchant(const PotionsMerchant&) = default;
    PotionsMerchant& operator=(const PotionsMerchant&) = default;

    /**
     * Applies the effect of the PotionsMerchant card on a player.
     * 
     * @param player - The player to apply the card's effect on.
     * @return - A message indicating the result of applying the card.
     */
    std::string applyCard(Player& player) const override;

    static const int HP_TO_GIVE = 10;
    static const int POTION_COST = 5;
};

#endif //EX4_Events_H