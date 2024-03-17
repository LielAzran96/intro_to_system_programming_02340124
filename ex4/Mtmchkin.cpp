
#include "Mtmchkin.h"
#include <sstream>
#include "utilities.h"
#include <algorithm>
#include <fstream>
#include "Players/Player.h"
#include "Cards/Card.h"
#include "Players/Behavior.h" // Include the Behavior header file here
#include "Players/Job.h" // Include the Behavior header file here

static bool playerComparator(const shared_ptr<Player>& player1, const shared_ptr<Player>& player2) {
    return *player1 < *player2; 
} 

static bool checkNameCorrectness(const string& name) {
    return (name.length() >= 3 && name.length() <= 15);
}

static void updatePlayersVector(vector<shared_ptr<Player>>& players, std::ifstream& playersFile) {

    std::string line;
    while (std::getline(playersFile, line)) {
        std::istringstream extractedData(line);
        std::string name, job, behavior;
        if (extractedData >> name >> job >> behavior) {
            if(checkNameCorrectness(name) && (job == "Warrior" || job == "Sorcerer") && (behavior == "Responsible" || behavior == "RiskTaking")) {
                players.push_back(shared_ptr<Player>(new Player(name)));
                players.back()->setJob(job);
                players.back()->setBehavior(behavior);
            } 
            else {
                throw std::runtime_error("Invalid Players File");
            }
        }
    }
}

static void updateCardQueue(queue<shared_ptr<Card>>& Cards, std::ifstream& cardsFile) {
    std::string line;
    while (std::getline(cardsFile, line)) {
        shared_ptr<Card> tempCard = Card::createCard(line);
        if(!tempCard) {
            throw std::runtime_error("Invalid Cards File");
        }
    }
}
    
Mtmchkin::Mtmchkin(const string& deckPath, const string& playersPath) {

    std::ifstream playersFile(playersPath);
    if(!playersFile) {
        throw std::runtime_error("Cannot open players file"); 
    }
    std::ifstream cardsFile(deckPath);
    if(!cardsFile) {
        throw std::runtime_error("Cannot open cards file"); 
    }
    updatePlayersVector(m_players, playersFile);
    updateCardQueue(m_Cards, cardsFile);

    this->m_turnIndex = 1;
}

void Mtmchkin::playTurn(Player& player) {
    string resultOfTurn;
    setCurrentCard();
    printTurnDetails(m_turnIndex, player, *m_currentCard);
    resultOfTurn = m_currentCard->applyCard(player);
    printTurnOutcome(resultOfTurn);
    m_turnIndex++;
}

void Mtmchkin::playRound() {
    printRoundStart();
    auto iterator = m_players.begin();
    while (iterator != m_players.end()) {
        m_currentPlayer = *iterator; // Dereference the shared_ptr<Player> 
        playTurn(*m_currentPlayer); // Dereference the Player

        if (m_currentPlayer->isKnockedOut()) {
            iterator = m_players.erase(iterator); // Erase the player and update the iterator
        } else {
            ++iterator; 
        }
    }

    printRoundEnd();
    printLeaderBoardMessage();
    int playersCounter = 1;
    /*sorting the players vector*/
    std::sort(m_playersSorted.begin(), m_playersSorted.end() , playerComparator);
    for(const shared_ptr<Player>& player : m_playersSorted) {
        printLeaderBoardEntry(playersCounter, *player);
    }
    printBarrier();
}

bool Mtmchkin::isGameOver() const {
    for(const shared_ptr<Player>& player : m_playersSorted) {
        if(player->getLevel() == GAME_MAX_LEVEL) {
            return true;
        }
    }
    return m_players.empty(); //false if not empty - and then the game continues
}

void Mtmchkin::play() {
    printStartMessage();
    int playersCounter = 1;
    for(const std::shared_ptr<Player>& player : m_players) {
        printStartPlayerEntry(playersCounter,*player);
        playersCounter++;
    }
    printBarrier();
    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    if(m_playersSorted[0]->getLevel() == GAME_MAX_LEVEL) {
        printWinner(*m_playersSorted[0]);
    }
    else {
        printNoWinners();
    }
}

void Mtmchkin::setCurrentCard() {
    m_currentCard = m_Cards.front();
    m_Cards.push(m_currentCard);
    m_Cards.pop();
     
}
Player& Mtmchkin::getCurrentPlayer() const{
    return *m_currentPlayer;
}

Card& Mtmchkin::getCurrentCard() const{
    return *m_currentCard;
}

// void Mtmchkin::updateGameStatus() {
//     if(m_currentPlayer->getLevel() == GAME_MAX_LEVEL) {
//         m_status = GameStatus::Win;
//     }
// }
