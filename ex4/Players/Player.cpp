#include "Player.h"
#include "../Mtmchkin.h"
#include "Job.h"
#include "Behavior.h"
using std::string;
using std::unique_ptr;

/*initialize the Final level according to the game's laws.*/
const int Player::FINAL_LEVEL = Mtmchkin::GAME_MAX_LEVEL; 

Player::Player(const string name) : m_name(name), m_level(INITIAL_LEVEL),
    m_force(DEFAULT_FORCE), m_hp(HealthPoints()), m_coins(INITIAL_COINS), m_job(nullptr), m_behavior(nullptr) {};

string Player::getDescription() const {
    return m_name + ", " + m_job->getName() + " with " + m_behavior->getName() +
     " behavior " + "(level " + std::to_string(m_level) + ", force " + std::to_string(m_force) + ")";
}

string Player::getName() const {
    return m_name;
}

int Player::getLevel() const {
    return m_level;
}

int Player::getForce() const {
    return m_force;
}

int Player::getHealthPoints() const {
    return m_hp.getCurrentHP();
}

int Player::getMaxHp() const {
    return m_hp.getMaxHP();
}

int Player::getCoins() const {
    return m_coins;
}

void Player::levelUp() {
    if(m_level < FINAL_LEVEL) {
        m_level++;
    }
}

bool Player::updateForce(const int forceToUpdate) {
    bool isUpdated = true;
    m_force += forceToUpdate;
    if(m_force < 0) {
        m_force = 0;
        isUpdated = false;   
    }
    return isUpdated;
}

void Player::heal(const int hpToAdd) {
    m_hp += hpToAdd;
}

void Player::damageHP(const int hpToRemove) {
    m_hp -= hpToRemove;
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

int Player::getCombatPower() const {
   return m_job->getPower(*this);
}

void Player::setBehavior(unique_ptr<Behavior> behavior) {
  m_behavior = std::move(behavior);
}

const Behavior& Player::getBehavior() const {
    return *m_behavior;
}

void Player::setJob(unique_ptr<Job> job) {
    m_job = std::move(job);
}

const Job& Player::getJob() const {
    return *m_job;
}

bool operator<(const Player& player1, const Player& player2) {
    if (player1.m_level != player2.m_level) {
        return player1.m_level > player2.m_level; // Sort by level from high to low
    } else if (player1.m_coins != player2.m_coins) {
        return player1.m_coins > player2.m_coins; // Sort by coins from high to low
    } else {
        return player1.m_name < player2.m_name; // Sort by name in lexicographical order
    }
}


