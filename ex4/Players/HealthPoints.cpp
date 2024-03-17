#include "HealthPoints.h"
 /**
     * checkHealthPointsValues - check if the health point reached to max or below zero, and changes health points accordinly if needed
     *
     * @param healthPoints - The current Health Points after adding/removing health points.
     * @param maxHealthPoints - The maximal Health Points.
*/
static void checkHealthPointsValues(int& healthPoints, const int maxHealthPoints);

/*c'tor*/
HealthPoints::HealthPoints(const int maxHealthPoints) : m_healthPoints(maxHealthPoints), m_maxHealthPoints(maxHealthPoints){
    // if(maxHealthPoints<=0) {
    //     throw HealthPoints::InvalidArgument();
    // }

}

static void checkHealthPointsValues(int& healthPoints, const int maxHealthPoints) {
    if(healthPoints > maxHealthPoints) {
        healthPoints = maxHealthPoints;
    }
    else if(healthPoints < 0){
        healthPoints = 0;
    }
}

// int HealthPoints::getCurrentHP() const {
//     return m_healthPoints;
// }

HealthPoints& HealthPoints::operator+=(const int HealthPointToAdd) {
    m_healthPoints += HealthPointToAdd;
    checkHealthPointsValues(m_healthPoints, m_maxHealthPoints);
    return *this;
}

HealthPoints& HealthPoints::operator-=(const int HealthPointToRemove) {
    return *this += (-HealthPointToRemove);
}

/*HealthPoints + int*/
HealthPoints HealthPoints::operator+(const int HealthPointToAdd) const{
    HealthPoints result(*this);
    result += HealthPointToAdd;
    return result;
}

HealthPoints HealthPoints::operator-(const int HealthPointToRemove) const{
    HealthPoints result(*this);
    result -= HealthPointToRemove;
    return result;
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& healthPoints) {
    return os << healthPoints.m_healthPoints << "(" << healthPoints.m_maxHealthPoints << ")";
}

/*boolean operators */
bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2) {
    return healthPoints1.m_healthPoints == healthPoints2.m_healthPoints;
}

bool operator<(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2) {
    return healthPoints1.m_healthPoints < healthPoints2.m_healthPoints;
}

bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2) {
    return !(healthPoints1 == healthPoints2);
}

bool operator<=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2) {
    return !(healthPoints2 < healthPoints1);
}

bool operator>(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2) {
    return healthPoints2 < healthPoints1;
}

bool operator>=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2) {
    return healthPoints2 <= healthPoints1;
}

/*int + HealthPoints*/
HealthPoints operator+(const int healthPointsToAdd, const HealthPoints& currentHealthPoints) {
    HealthPoints result(currentHealthPoints);
    return result+= healthPointsToAdd;
}

