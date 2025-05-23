#pragma once
#include "User.h" 

class PremiumUser : public User { // Inherits all methods and attributes of User
public:
    // Default constructor for BasicUser
    PremiumUser() : User() {
        cycleCount = 5; //sets the specific cycle count for BasicUser
    }

    // overrides base class to show basic user
    void displayInfo() const override;
};