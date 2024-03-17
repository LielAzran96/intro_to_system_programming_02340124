#ifndef EX4_HealthPoints_H
#define EX4_HealthPoints_H
#include <iostream>

class HealthPoints {
public:
    /**
     * C'tor of HealthPoints class
     *
     * @param maxHealthPoints - The maximal Health Points.
     * @return
     *      A new instance of Health Points.
    */
    HealthPoints(const int maxHealthPoints = DEFAULT_MAX_HP);
    /*default d'tor & copy c'tor & assignment operator*/
    HealthPoints(const HealthPoints& ) = default;
    ~HealthPoints() = default;
    HealthPoints& operator=(const HealthPoints& otherHealthPoints) = default;

    HealthPoints& operator+=(const int HealthPointToAdd);
    HealthPoints& operator-=(const int HealthPointToRemove);

    HealthPoints operator+(const int HealthPointToAdd) const;
    HealthPoints operator-(const int HealthPointToRemove) const;

    /*class for exceptions - if a negative number is passed to the c'tor we'll throw an exception from this type*/
    class InvalidArgument {};

    // int getCurrentHP() const;
    
// private:
    int m_healthPoints; 
    int m_maxHealthPoints; 
    static const int DEFAULT_MAX_HP = 100;

    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& healthPoints);
    friend bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
    friend bool operator<(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);

};

bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
bool operator<=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
bool operator>(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
bool operator>=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
HealthPoints operator+(const int healthPointsToAdd, const HealthPoints& healthPoints2);


#endif //EX4_HealthPoints_H