#pragma once  
#include <string>  
#include "Date.h"    
#include <memory>  
#include <map>  
using namespace std;  

enum Mood {
	Sad = 1,
	Frustrated,
	Neutral,
	Happy,
	Calm
};

inline map<Mood, string> moodMap={
	{Mood::Sad, "Sad"},
	{Mood::Frustrated, "Frustrated"},
	{Mood::Neutral, "Neutral"},
	{Mood::Happy, "Happy"},
	{Mood::Calm, "Calm"}
};

class User {  
protected:  
  string name;  
  Date date;  
  short int cycleCount;  
  Mood moodBefore;  
  Mood moodAfter;  
public:  
  // Default constructor  
  User() :name{ " " }, date{}, cycleCount(0), moodBefore(Mood::Neutral), moodAfter(Mood::Neutral) {};  
  virtual ~User() {}; // Change pure virtual destructor to a virtual destructor  

  // Setters  
  void setName();  
  void setDate();  
  virtual void setCycle();  
  void setBeforeMood();  
  void setAfterMood();  

  // Getters  
  string getName() const;  
  Date getDate() const;  
  short int getCycle() const; 
  Mood getMood() const;
  Mood getBeforeMood() const;  
  Mood getAfterMood() const;  

  // Poly  
  virtual void displayInfo() const;  

  virtual void getSummary() const = 0;  
  void logToFile(User& user)const;



};