#pragma once
#include "User.h" 

class BasicUser : public User { // Inherits all methods and attributes of User
public:
    // Default constructor for BasicUser
    BasicUser() : User() {}
    
    // overrides base class to show basic user
    void setCycle() override;
    void displayInfo() const override;

};