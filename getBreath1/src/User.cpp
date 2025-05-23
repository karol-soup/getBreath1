#include "../include/Date.h"
#include "../include/Mood.h"
#include "../include/User.h"
#include "../include/getFunctions.h"
#include <iostream>
#include <string>

using namespace std;

//User setters
void User::setName() {
	string name;
	cout << "I'm getBreath what's your name?\n";
	while (true) {
		getline(cin, name);
		if (name.empty()) {
			cout << "Invalid input. Please try again.\n";
		}
		else if (!isValidName(name)) {
			cout << "Name is excessivly long. No more than 35 character. Please try again.\n";
		}
		else {
			break;
		}
	}
	this->name = name;
}
void User::setDate() { this->date = getDate(); }
void User::setCycle() {
	short int cycles;
	cout << "How many breathing cycles would you like to do today? \n";
	while (true) {
		cin >> cycles;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			cout << "Invalid input. Please try again. \n";

		}
		else if (!isValidCycle(cycles)) {
			cout << "Cycles entered must be between 1-15. \n";

		}
		else {
			break;
		}
	}
	this->cycleCount = cycles;
}
void User::setBeforeMood(Mood newMood) { this->moodBefore = getMood(); }
void User::setAfterMood(Mood newMood) { this->moodAfter = getMood(); }

//User getters
string User::getName() const { return name; }
Date User::getDate() const { return date; }
short int User::getCycle() const { return cycleCount; }
Mood User::getBeforeMood() const { return moodBefore; }
Mood User::getAfterMood() const { return moodAfter; }

void User::displayInfo() const {
	cout << "--- User Information ---\n";
	cout << "Name: " << name << endl;
	cout << "Registration Date: " << getDate() << endl;
	cout << "Cycle Count: " << getCycle() << endl;
	cout << "Before Mood: " << getBeforeMood() << endl;
	cout << "After Mood: " << getAfterMood() << endl;
}