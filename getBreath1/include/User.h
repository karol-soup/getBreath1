#pragma once  
#include <string>  
#include "Date.h"  
#include "Mood.h"  
#include <memory>  
using namespace std;  

class User {  
private:  
   string name;  
   Date date;  
   short int cycleCount;  
   Mood moodBefore;  
   Mood moodAfter;  
public:  
   // Default constructor  
   User() :name{ " " }, date{}, cycleCount(0), moodBefore{ Neutral }, moodAfter{ Neutral } {};  
   virtual ~User() {}; // Change pure virtual destructor to a virtual destructor  

   // Setters  
   void setName();  
   void setDate();  
   void setCycle();  
   void setBeforeMood(Mood newMood);  
   void setAfterMood(Mood newMood);  

   // Getters  
   string getName() const;  
   Date getDate() const;  
   short int getCycle() const;  
   Mood getBeforeMood() const;  
   Mood getAfterMood() const;  

   // Poly  
   virtual void displayInfo() const;  
   virtual void getSummary() const;  
   virtual void getUsers() const;  
   unique_ptr<vector<User>> getUsers();  
};