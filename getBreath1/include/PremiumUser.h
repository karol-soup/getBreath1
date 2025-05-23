#pragma once
#include "User.h" 

class PremiumUser : public User { // Inherits all methods and attributes of User
public:
    // Default constructor for BasicUser
    PremiumUser() : User() {
        cycleCount = 5; //sets the specific cycle count for BasicUser
    }

    PremiumUser(const std::string& name, const Date& date, Mood bMood, Mood aMood) : User(name, date, 5, bMood, aMood) {}

    // overrides base class to show basic user
    void displayInfo() const override;
};