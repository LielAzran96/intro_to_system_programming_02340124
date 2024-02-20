//#include <iostream>
#include "utilities.h"
#include "Player.h"
#include "Mtmchkin.h"

/*initialize the Final level according to the game's laws.*/
const int Player::FINAL_LEVEL = Mtmchkin::GAME_MAX_LEVEL; 


Player::Player(const char* name, const int maxHp, int force) : m_name(name),
    m_level(INITIAL_LEVEL), m_force((force < 0) ? DEFAULT_FORCE : force), 
    m_maxHp((maxHp <= 0) ? DEFAULT_MAX_HP : maxHp), m_hp(m_maxHp), m_coins(INITIAL_COINS) {}


void Player::printInfo() const {
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_hp, m_coins);
}

void Player::levelUp() {
    if(m_level < FINAL_LEVEL) {
        m_level++;
    }
}

int Player::getLevel() const {
    return m_level;
}

void Player::buff(const int forceToAdd) {
    if(forceToAdd >= 0) {
        m_force += forceToAdd;
    }
}

void Player::heal(const int hpToAdd){
    if(hpToAdd >= 0) {
        /*raise the hp until it reaches to maximum of max_hp*/
        if(m_maxHp - m_hp < hpToAdd) {
            m_hp = m_maxHp;
        }
        else {
            m_hp += hpToAdd;
        }
    }
}

void Player::damage(const int hpToRemove) {
    if(hpToRemove >= 0) {
        if(m_hp > hpToRemove) {
            m_hp -= hpToRemove;
        }
        else {
            m_hp = 0;
        }
    }
}

bool Player::isKnockedOut() const {
    return (m_hp == 0) ? true : false;
}

void Player::addCoins(const int coinsToAdd) {
    if(coinsToAdd >= 0) {
        m_coins += coinsToAdd;
    }
}

bool Player::pay(const int coinsToPay) {
    /*also handles the case of coinsToPay<0*/
    if(coinsToPay > m_coins || coinsToPay < 0) {
        return false;
    }
    m_coins -= coinsToPay;
    return true;
}

int Player::getAttackStrength() const {
    return m_force + m_level;
}
