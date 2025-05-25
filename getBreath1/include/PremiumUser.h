#pragma once
#include "User.h" 

class PremiumUser : public User { // Inherits all methods and attributes of User
public:
    // Default constructor for BasicUser
    PremiumUser() : User() {}

    // overrides base class to show basic user
    void setCycle() override;
    void displayInfo() const override;
    void getSummary() const override;
};