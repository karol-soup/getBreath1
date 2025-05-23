#pragma once
#include "User.h" 

class BasicUser : public User { // Inherits all methods and attributes of User
public:
    // Default constructor for BasicUser
    BasicUser() : User() { 
        cycleCount = 2; //sets the specific cycle count for BasicUser
    }
 
    // overrides base class to show basic user
    void displayInfo() const override;
};