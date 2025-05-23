#pragma once
#include <string>
#include "Date.h"
#include "Mood.h"

using namespace std;

class User {
protected:
	string name;
	Date date;
	short int cycleCount;
	Mood moodBefore;
	Mood moodAfter;
public:
    // Default constructor
    User() :name{ " " }, date{}, cycleCount(0), moodBefore{ Neutral }, moodAfter{ Neutral } {};
    virtual ~User() = 0;
   
    //setters
    void setName();
    void setDate();
    void setCycle();
    void setBeforeMood(Mood newMood);
    void setAfterMood(Mood newMood);

    //getters
    string getName() const;
    Date getDate() const;
    short int getCycle() const;
    Mood getBeforeMood() const;
    Mood getAfterMood() const;

    //poly
    virtual void displayInfo() const;
};