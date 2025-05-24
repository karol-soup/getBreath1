#include "../include/Date.h"
#include "../include/User.h"
#include "../include/utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <ctime>
#include <stdexcept>
#include <map>
#include <unordered_map>
using namespace std;

//User setters
void User::setName() {
	string name;
	cout << "I'm getBreath what's your name?\n";
	while (true) {
		try {
			getline(cin, name);
			if (name.empty()) {
				cout << "Invalid input. Please try again.\n";
			}
			isValidName(name);
			this->name = name;
			break;
		}
		catch (const invalid_argument& e) {
			cout << e.what() << endl;
		}
	}

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
		try {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits <streamsize>::max(), '\n');
				throw invalid_argument("Invalid input. Please try again. \n");
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//to discard any other input
			isValidCycle(cycles);//will throw std::out_of_range if 'cycles' is invalid
		   // If point, no exception was thrown, is valid.
				this->cycleCount = cycles;
				break;
		}
			catch (const invalid_argument& e) {
				cout << e.what() << endl;
			}
			catch (const out_of_range& e) {
				cout << e.what() << endl;
			}
		
	}
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
		try {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw invalid_argument("Invalid input. Please try again. \n");
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //to discard anything else
			isValidMood(mood);
			return static_cast <Mood>(mood);
			break;
		}
		catch (const out_of_range& e) {
			cout << e.what() << endl;
		}
		catch (const invalid_argument& e) {
			cout << e.what() << endl;
		}
	}
}
Mood User::getBeforeMood() const { return moodBefore; }
Mood User::getAfterMood() const { return moodAfter; }

void User::displayInfo() const {
	cout << "--- User Information ---\n";
	cout << "Name: " << name << endl;
	cout << " Date: " << getDate() << endl;
	cout << "Cycle Count: " << getCycle() << endl;
	cout << "Before Mood: " << getBeforeMood() << endl;
	cout << "After Mood: " << getAfterMood() << endl;
}

void User::getSummary() const {
	fstream userLog("userLogs.dat", ios::in | ios::binary);//opening file in input mode, and ensuring previos work isnt erased
	if (!userLog) {
		cout << "Couldn't open file.\n";
	}
	else {
		unordered_map<Mood, int> moodCounts;
		auto users = make_unique<std::vector<User>>();
		User user;
		while (userLog.read(reinterpret_cast<char*>(&user), sizeof(user))) {
			users->push_back(user);
		}
		userLog.close();
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
}

void User::logToFile(User& user)const {
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
