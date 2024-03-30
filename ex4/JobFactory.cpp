#include "JobFactory.h"

unique_ptr<Job> JobFactory::create(const string& JobName) {
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