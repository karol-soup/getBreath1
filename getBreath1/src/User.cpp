#include "../include/Date.h"
#include "../include/User.h"
#include "../include/utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <ctime>
#include <map>
#include <unordered_map>
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
void User::setDate() {
	Date date;
	date.setDate();
	this->date = date.getDate();
}
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
void User::setBeforeMood() { this->moodBefore = getMood(); }
void User::setAfterMood() { this->moodAfter = getMood(); }

//User getters
string User::getName() const { return name; }
Date User::getDate() const { return date; }
short int User::getCycle() const { return cycleCount; }
Mood User::getMood() const{
	short int mood;
	cout << "Using our scale 1-5, how are you feeling at the moment?\n"
		<< "(1 - Sad, 2 - Frustrated, 3 - Neutral, 4 - Happy, 5 - Calm)\n";
	while (true) {
		cin >> mood;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please try again.\n";
		}
		else if (!isValidMood(mood)) {
			cout << "Input must be between 1-5. Please try again.\n";
		}
		else break;
	}

	return static_cast <Mood>(mood);
}
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

void User::getSummary() const {
	fstream userLog("userLogs.dat", ios::in | ios::binary);//opening file in input mode, and ensuring previos work isnt erased
	auto users = make_unique<std::vector<User>>();
	User user;
	if (!userLog) {
		cout << "Couldn't open file.\n";
		return;
	}
	while (userLog.read(reinterpret_cast<char*>(&user), sizeof(User))) {
		users->push_back(user);
	}
	userLog.close();
		unordered_map<Mood, int> moodCounts;
		if (users->empty()) {
			cout << "No log data on file.\n";
		}
		else {

			cout << endl << getName() << "'s summary of log history\n";

			cout << "Before taking a breath:\n";
			for (const auto& user : *users) { // derefrenceing 
				moodCounts[user.moodBefore]++; //will get mood(key) and add 1 each iteration of the same mood
			}
			for (const auto& pair : moodCounts) {
				cout << "You felt: " << moodMap.at(pair.first) << " " << pair.second << " time(s)\n";
			}

			moodCounts.clear();

			cout << "After taking a breath:\n";
			for (const auto& user : *users) { // derefrenceing 
				moodCounts[user.moodAfter]++; //will get mood(key) and add 1 each iteration of the same mood
			}
			for (const auto& pair : moodCounts) {
				cout << "You felt: " << moodMap.at(pair.first) << " " << pair.second << " time(s)\n";
			}
			cout << "Remember you breathe from time to time :)\n";
		}

}

void User::logToFile(User& user) {
	fstream userLog; //creating file
	userLog.open("userLogs.dat", ios::out | ios::app | ios::binary); //opening file in input mode, and ensuring previos work isnt erased


	if (!userLog.is_open()) {

		cout << "Couldnt open file" << endl;
	}
	else {
		userLog.write(reinterpret_cast<char*>(&user), sizeof(User));//writing in info about user

		userLog.close();

	}
}
