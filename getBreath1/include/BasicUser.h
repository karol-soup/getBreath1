#pragma once
#include "User.h" 

class BasicUser : public User { // Inherits all methods and attributes of User
public:
    // Default constructor for BasicUser
    BasicUser() : User() { 
        cycleCount = 2; //sets the specific cycle count for BasicUser
    }

    BasicUser(const std::string& name, const Date& date, Mood bMood, Mood aMood) : User ( name, date, 2, bMood, aMood ) {}
      
    // overrides base class to show basic user
    void displayInfo() const override;
};