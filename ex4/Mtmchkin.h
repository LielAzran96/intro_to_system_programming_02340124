
#pragma once

#include <string>
#include <memory>
#include <vector>
#include <queue>

#include <set>
#include <queue>
using std::string;
using std::shared_ptr;
using std::vector;
using std::queue;
class Player;
class Card;
/*
 * GameStatus:
 * MidGame - The game is still active and the players continue to encounter cards.
 * Win - One (or more) of the players reached level 10.
 * Loss - The player's HP is 0.
*/
// enum class GameStatus{Win, Loss, MidGame};

class Mtmchkin{
private:
    std::vector<shared_ptr<Player>> m_players;
    vector<shared_ptr<Player>> m_playersSorted;
    std::queue<shared_ptr<Card>> m_Cards;
    shared_ptr<Player> m_currentPlayer;
    shared_ptr<Card> m_currentCard;
    //GameStatus m_status;
    int m_turnIndex;

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

    void setCurrentCard();

    // GameStatus getGameStatus() const;
    // void updateGameStatus();

    Player& getCurrentPlayer() const;
    Card& getCurrentCard() const;
    
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

    Mtmchkin() = default;
    /**
     * Plays the entire game
     * 
     * @return - void
    */
    void play();
   
    static const int GAME_MAX_LEVEL = 10;

};
