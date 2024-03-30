
#ifndef EX4_BehaviorFactory_H
#define EX4_BehaviorFactory_H

#include <memory>
#include "Players/Behavior.h"
#include <stdexcept> 

using std::string;
using std::unique_ptr;

class BehaviorFactory {
public:
    /**
     * C'tor of BehaviorFactory class
     *
     * @return
     *      A new instance of BehaviorFactory.
     */
    explicit BehaviorFactory() = default;
    /**
    * copy C'tor of the factory:
    *deleted
    */
    BehaviorFactory(const BehaviorFactory&) = delete;

    /**
      * Assignment C'tor of the factory:
      *deleted
      */
    BehaviorFactory& operator=(const BehaviorFactory&) = delete;

    /**
    * D'tor of the class: default
    */
    ~BehaviorFactory() = default;

    /**
     * Create Behavior function
     *
     * @param behaviorName - the behavior of the Player.
     * @return
     *     std::unique_ptr<Behavior> of the new instance of behavior.
     */
    unique_ptr<Behavior> create(const string& behaviorName);
};

#endif //EX04_CARDFACTORY_H