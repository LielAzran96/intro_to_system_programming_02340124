
#pragma once

#include <string>
#include <memory>
#include <vector>
#include <queue>
#include "BehaviorFactory.h"
#include "JobFactory.h"
#include "CardFactory.h"
#include <fstream>
using std::string;
using std::shared_ptr;
using std::unique_ptr;
using std::vector;
using std::queue;

class Player;
class Card;

class Mtmchkin{
private:
    vector<shared_ptr<Player>> m_players;
    /*sorted vector of players based on their ranking*/
    vector<std::shared_ptr<Player>> m_playersSorted;
    queue<unique_ptr<Card>> m_cards;
    shared_ptr<Player> m_currentPlayer;
    unique_ptr<Card> m_currentCard;
    int m_turnIndex;
    unique_ptr<BehaviorFactory> m_behaviorFactory;
    unique_ptr<JobFactory> m_jobFactory;
    unique_ptr<CardFactory> m_cardFactory;
    bool m_isAnyPlayerReachedMaxLevel; //default c'tor will initialize it to false

    /**
     * Playes a single turn for a player
     * 
     * @param player - the player to play the turn for
     * 
     * @return - void
    */
    void playTurn(Player& player);

    /**
     * Plays a single round of the game
     * 
     * @return - void
    */
    void playRound();

    /**
     * Checks if the game is over
     * 
     * @return - true if the game is over, false otherwise
    */
    bool isGameOver() const;

    /**
     * updatePlayersVector - update the m_players vector based in the input file
     * 
     * @return - void
    */
    void updatePlayersVector(std::ifstream& playersFile);

    /**
     * updateCardQueue - update the m_cards queue based in the input file
     * 
     * @return - void
    */
    void updateCardQueue(std::ifstream& cardsFile);

public:
    /**
     * Constructor of Mtmchkin class
     * 
     * @param deckPath - path to the deck file
     * @param playersPath - path to the players file
     * 
     * @return - Mtmchkin object with the given deck and players
     *
    */
    Mtmchkin(const string& deckPath, const string& playersPath);
    
    /*default d'tor*/
    
    /*delete assignment operator and copy c'tor*/
    ~Mtmchkin() = default;
    Mtmchkin(const Mtmchkin&) = delete;
    Mtmchkin& operator=(const Mtmchkin&) = delete;
    
    /**
     * Plays the entire game
     * 
     * @return - void
    */
    void play();
   
    static const int GAME_MAX_LEVEL = 10;

};
