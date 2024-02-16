#include <iostream>
#include "Player.h"

Player::Player(const char* name, const int maxHp, int force) : m_name(new char[strlen(name) + 1]),
    m_level(INITIAL_LEVEL), m_force((force < 0) ? DEFAULT_FORCE : force), 
    m_maxHp((maxHp <= 0) ? DEFAULT_MAX_HP : maxHp), m_hp(m_maxHp), m_coins(INITIAL_COINS) {

    strcpy(m_name, name);
}

Player::Player(const Player& otherPlayer) : m_name(new char[strlen(otherPlayer.m_name) + 1]), 
    m_level(otherPlayer.m_level), m_force(otherPlayer.m_force), m_maxHp(otherPlayer.m_maxHp),
    m_hp(otherPlayer.m_hp), m_coins(otherPlayer.m_coins) {

    /*copy all the other variables*/            
    strcpy(m_name, otherPlayer.m_name);
}

Player::~Player() {
    delete[] m_name;
}

Player& Player::operator=(const Player& otherPlayer) {
    if(this == &otherPlayer) {
        return *this;
    }
    delete[] m_name;
    m_name = new char[strlen(otherPlayer.m_name) + 1];
    strcpy(m_name, otherPlayer.m_name);
    m_maxHp = otherPlayer.m_maxHp;
    m_level = otherPlayer.m_level;
    m_force = otherPlayer.m_force;
    m_hp = otherPlayer.m_hp;
    m_coins = otherPlayer.m_coins;
    return *this;
}

void Player::printInfo() const {
    printPlayerInfo(m_name, m_level, m_force, m_hp, m_coins);
}

void Player::levelUp() {
    m_level = (m_level == FINAL_LEVEL) ? m_level : m_level + 1;
}

int Player::getLevel() const {
    return m_level;
}

void Player::buff(int forceToAdd) {
    if(forceToAdd >= 0) {
        m_force += forceToAdd;
    }
}

void Player::heal(int hpToAdd){
    if(hpToAdd >= 0) {
        /*raise the hp until it reaches to maximum of max_hp*/
        if(m_maxHp - m_hp < hpToAdd) {
            m_hp += m_maxHp - m_hp;
        }
        else {
            m_hp += hpToAdd;
        }
    }
}

void Player::damage(int hpToRemove) {
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

void Player::addCoins(int coinsToAdd) {
    if(coinsToAdd >= 0) {
        m_coins += coinsToAdd;
    }
}

bool Player::pay(int coinsToPay) {
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
