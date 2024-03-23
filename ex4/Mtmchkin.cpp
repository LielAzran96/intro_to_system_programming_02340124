#include "Mtmchkin.h"
#include <sstream>
#include "utilities.h"
#include <algorithm>
#include "Players/Player.h"
#include "Cards/Card.h"
#include "Players/Behavior.h" // Include the Behavior header file here
#include "Players/Job.h" // Include the Behavior header file here
// #include <ios>

// static void preprocessInput(string& input) {
//     /*Remove all carriage return characters ('\r') from the input string*/
//     string processedInput;
//     for (char c : input) {
//         if (c != '\r') {
//             processedInput += c;
//         }
//     }
//     input = processedInput;
// }

static bool checkNameCorrectness(const string& name) {
    if(name.length() < 3 || name.length() > 15) {
        return false;
    }
     for (char c : name) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
            return false;
        }
    }
    return true;
}



Mtmchkin::Mtmchkin(const string& deckPath, const string& playersPath) : m_players(), m_playersSorted(),
m_cards(), m_currentPlayer(nullptr), m_currentCard(nullptr), m_turnIndex(0), m_behaviorFactory(new BehaviorFactory()), 
m_jobFactory(new JobFactory()), m_cardFactory(new CardFactory()), m_isAnyPlayerReachedMaxLevel(false)  {

    std::ifstream playersFile(playersPath);
    if(!playersFile) {
        throw std::runtime_error("Invalid Players File"); 
    }
    std::ifstream cardsFile(deckPath);
    if(!cardsFile) {
        throw std::runtime_error("Invalid Cards File"); 
    }
    
    updatePlayersVector(playersFile);
    m_playersSorted = m_players;
    updateCardQueue(cardsFile);
    this->m_turnIndex = 1;
}

void Mtmchkin::updatePlayersVector(std::ifstream& playersFile) {
    std::string line;
    while (std::getline(playersFile, line)) {
        std::istringstream extractedData(line);
        std::string name, job, behavior, additionalInformation;
        if (!(extractedData >> name >> job >> behavior) || !checkNameCorrectness(name) || (extractedData >> additionalInformation)) {
            throw std::runtime_error("Invalid Players File"); 
        }
        m_players.push_back(shared_ptr<Player>(new Player(name)));
        m_players.back()->setJob(m_jobFactory->create(job));
        m_players.back()->setBehavior(m_behaviorFactory->create(behavior));
        /*stop reciving input if there are 7 or more players (the maximum allowed is 6 players)*/
        if(m_players.size() > 6) {
            break;
        }
    }
    if(m_players.size() <2 || m_players.size() > 6) {
        throw std::runtime_error("Invalid Players File"); 
    }
}

void Mtmchkin::updateCardQueue(std::ifstream& cardsFile) {
    std::string word;
    while (cardsFile >> word) {
        m_cards.push(m_cardFactory->create(cardsFile, word));
    }
    if(m_cards.size() < 2) {
        throw std::runtime_error("Invalid Cards File"); 
    }    
}
    
void Mtmchkin::playTurn(Player& player) {
    string resultOfTurn;
    m_currentCard = std::move(m_cards.front());
    printTurnDetails(m_turnIndex, player, *m_currentCard);
    resultOfTurn = m_currentCard->applyCard(player);
    printTurnOutcome(resultOfTurn);
    m_turnIndex++;
    m_cards.pop();
    m_cards.push(std::move(m_currentCard));
}

void Mtmchkin::playRound() {
    printRoundStart();
    auto iterator = m_players.begin();
    while(iterator != m_players.end()) {
        m_currentPlayer = *iterator;// Dereference the shared_ptr<Player>
        playTurn(*m_currentPlayer); // Dereference the Player

        if (m_currentPlayer->isKnockedOut()) {
            iterator = m_players.erase(iterator); // Erase the player and update the currentPlayer
        } else {
            if(m_currentPlayer->getLevel() == GAME_MAX_LEVEL) {
                m_isAnyPlayerReachedMaxLevel = true;
            }
            ++iterator; 
        }
    }

    printRoundEnd();
    printLeaderBoardMessage();
    int playersCounter = 1;
    /*sorting the players vector*/
    std::sort(m_playersSorted.begin(), m_playersSorted.end(),
        [](const shared_ptr<Player>& player1, const shared_ptr<Player>& player2) {

            return *player1 < *player2;
        }
    );
    for(const shared_ptr<Player>& player : m_playersSorted) {
        printLeaderBoardEntry(playersCounter, *player);
        playersCounter++;
    }
    printBarrier();
}

bool Mtmchkin::isGameOver() const {
    if(m_isAnyPlayerReachedMaxLevel) {
        return true;
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
    if(m_isAnyPlayerReachedMaxLevel) {
        printWinner(*m_playersSorted[0]);
    }
    else {
        printNoWinners();
    }
}


