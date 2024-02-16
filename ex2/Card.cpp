#include "Card.h"

Card::Card(CardType type, const CardStats& stats) : m_effect(type), m_stats(stats) 
{}

void Card::applyEncounter(Player& player) const {
    switch(m_effect) {
        case CardType::Battle:
            /*winning the battle*/
            if(player.getAttackStrength() >= m_stats.force) {
                player.levelUp();
                player.addCoins(m_stats.loot);
                printBattleResult(true);
            }
            /*loosing the battle*/
            else {
                player.damage(m_stats.hpLossOnDefeat);
                printBattleResult(false);
            }
            break;
        case CardType::Buff:
        case CardType::Heal:
            if(player.pay(m_stats.cost)) {
                if(m_effect == CardType::Heal) {
                    player.heal(m_stats.heal);
                }
                else {
                    player.buff(m_stats.buff);
                }
            }
            break;
        case CardType::Treasure:
            player.addCoins(m_stats.loot);
            break;
        default:
            break;
    }
}

void Card::printInfo() const{
    switch(m_effect) {
        case CardType::Battle:
            printBattleCardInfo(m_stats);
            break;
        case CardType::Heal:
            printHealCardInfo(m_stats);
            break;
        case CardType::Buff:
            printBuffCardInfo(m_stats);
            break;
        case CardType::Treasure:
            printTreasureCardInfo(m_stats);
            break;
        default:
            break;
    }
}
