
#pragma once

#include "Monster.h"
#include <string>
#include <memory>
using std::unique_ptr;

class Player;

class Card {
public:
    /**
     * Gets the description of the card
     * 
     * @return - the description of the card
    */
    Card(const std::string& name) : m_cardName(name) {};
    virtual string getDescription() const;
    virtual string applyCard(Player& player) const = 0;
    virtual ~Card() = default;
    static unique_ptr<Card> createCard(const string& cardName);
protected:
    std::string m_cardName;
};

class Encounter : public Card {
public:
    Encounter() : Card(""), m_monster(new Monster()) {};
    string applyCard(Player& player) const override;
    string getDescription() const override;
    Monster& getMonster();
    void setCardName(const string& cardName);
    ~Encounter() = default;
private:
    std::unique_ptr<Monster> m_monster;
};


class SolarEclipse : public Card {
public:
    SolarEclipse() : Card(NAME) {};
    ~SolarEclipse() = default;
    string applyCard(Player& player) const override;
    static const int FORCE_TO_UPDATE = 1;
private:
    static const std::string NAME;
};

class PotionsMerchant : public Card {
public:
    PotionsMerchant() : Card(NAME) {};
    ~PotionsMerchant() = default;
    string applyCard(Player& player) const override;
    static const int HP_TO_GIVE = 10;
    static const int POTION_COST = 5;
private:
    static const std::string NAME;
};