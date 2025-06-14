#include "Card.h"

Card::Card(CardType type, const CardStats& stats) : m_effect(type), m_stats(stats) {}

void Card::applyEncounter(Player& player) const {
    bool isWinBattle = false;
    switch(m_effect) {
        case CardType::Battle:
            /*winning the battle*/
            if(player.getAttackStrength() >= m_stats.force) {
                isWinBattle = true;
                player.levelUp();
                player.addCoins(m_stats.loot);
            }
            /*loosing the battle*/
            else {
                isWinBattle = false;
                player.damage(m_stats.hpLossOnDefeat);
            }
            printBattleResult(isWinBattle);
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
