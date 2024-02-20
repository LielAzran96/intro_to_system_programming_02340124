#include "Mtmchkin.h"

/*c'tor*/
Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards)
    : m_player(playerName), m_cardsArray(copyCardsArray(cardsArray, numOfCards)),
      m_numberOfCards(numOfCards), m_status(GameStatus::MidGame), m_cardIndex(0) {}

/*copy c'tor*/
Mtmchkin::Mtmchkin(const Mtmchkin& mtmchkin)
    : m_player(mtmchkin.m_player), m_cardsArray(copyCardsArray(mtmchkin.m_cardsArray, mtmchkin.m_numberOfCards)),
      m_numberOfCards(mtmchkin.m_numberOfCards), m_status(mtmchkin.m_status), m_cardIndex(mtmchkin.m_cardIndex) {} 

/*d'tor*/
Mtmchkin::~Mtmchkin() {
    delete[] m_cardsArray;
}

/*assignment operator*/
Mtmchkin& Mtmchkin::operator=(const Mtmchkin& other) {
    if(this == &other) {
        return *this;
    }
    delete[] m_cardsArray;
    m_cardsArray = copyCardsArray(other.m_cardsArray, other.m_numberOfCards);
    m_numberOfCards = other.m_numberOfCards;
    m_status =other.m_status;
    m_cardIndex = other.m_cardIndex;
    return *this;
}

Card* Mtmchkin::copyCardsArray(const Card* cardsArray, int numOfCards) {
    Card* copyCardsArray = new Card[numOfCards];
    for (int i = 0; i < numOfCards; ++i) {
        copyCardsArray[i] = cardsArray[i];
    }
    return copyCardsArray;
}

void Mtmchkin::playNextCard() {
    m_cardsArray[m_cardIndex].printInfo();
    m_cardsArray[m_cardIndex].applyEncounter(m_player);
    m_player.printInfo();
    updateCardIndex();
    updateGameStatus(); /*check if the game is over or not, and update m_status accordingly*/
}

void Mtmchkin::updateCardIndex() {
    if(m_cardIndex < m_numberOfCards - 1) {
        m_cardIndex++;
    } 
    else {
        m_cardIndex = 0;
    }
}

GameStatus Mtmchkin::getGameStatus() const {
    return m_status;
}

bool Mtmchkin::isOver() const {
    return (m_status != GameStatus::MidGame) ? true : false;
}

void Mtmchkin::updateGameStatus() {
    if(m_player.getLevel() == GAME_MAX_LEVEL) {
        m_status = GameStatus::Win;
    }
    else if(m_player.isKnockedOut()) {
        m_status = GameStatus::Loss;
    }
}
