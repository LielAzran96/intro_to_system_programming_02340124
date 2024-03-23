
#ifndef EX4_JobFactory_H
#define EX4_JobFactory_H


#include <memory>
#include "Players/Job.h"
#include <stdexcept> 

using std::string;
using std::unique_ptr;

class JobFactory {
public:
    /**
     * C'tor of JobFactory class
     *
     * @return
     *      A new instance of JobFactory.
     */
    explicit JobFactory() = default;

    /*
    * copy C'tor of the factory:
    *deleted
    */
    JobFactory(const JobFactory&) = delete;

    /*
      * Assignment C'tor of the factory:
      *deleted
      */
    JobFactory& operator=(const JobFactory&) = delete;

    /**
    * D'tor of the class: default
    */
    ~JobFactory() = default;


    /**
     * Create Job function
     *
     * @param JobName - the Job of the Player.
     * @return
     *     std::unique_ptr<Job> of the new instance of Job.
     */
    unique_ptr<Job> create(const string& JobName) {
        if(JobName == "Warrior") {
            return unique_ptr<Job>(new Warrior());
        }
        else if(JobName == "Sorcerer") {
            return unique_ptr<Job>(new Sorcerer());
        }
        else {
            throw std::runtime_error("Invalid Players File"); 
        }
    }
};

#endif //EX4_JobFactory_H