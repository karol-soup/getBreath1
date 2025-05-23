#include "../include/Date.h"
#include "../include/Mood.h"
#include "../include/UserInfo.h"
#include "../include/beginBreathing.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <ctime>
#include <map>
#include <unordered_map>
#include <cstdlib>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono_literals;

Date::Date(int month, int day, int year) : month{ month }, day{ day }, year{ year } {};

Date Date:: getDate() {
	Date date;
	cout << "What is today date? (MM/DD/YYYY)\n";
	cin >> date;
	return date;
}

//in order to test
bool isValidMood(short mood) {
	return mood <=5 && mood >= 1;
}
bool isValidCycle(short cycle) {
	return cycle >= 1 && cycle <= 15;
}
bool isValidName(const string& name) {
	return !name.empty() && name.length() <= 35;
}

Mood getMood() {
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
//User setters
void User::setName(){
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
void User::setDate() { this->date = getDate();}
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
	this-> cycleCount = cycles;
}
void User::setBeforeMood(Mood newMood) { this->moodBefore = getMood(); }
void User::setAfterMood(Mood newMood) { this->moodAfter = getMood(); }
//User getters
string User::getName() const { return name; }
Date User::getDate() const { return date; }
short int User::getCycle() const { return cycleCount; }
Mood User::getBeforeMood() const { return moodBefore; }
Mood User::getAfterMood() const { return moodAfter; }

void countdown(const int& num) {
	this_thread::sleep_for(1s);// pause for 1 sec
	for (int i = num; i >= 1;i--) {
		cout << i << endl;
		this_thread::sleep_for(1s);//pause for 1 sec
	}
}

void timer(const int& cycles) {

	for (int i = 0;i < cycles;i++) {
		cout << "Breath in...4.." << endl;
		countdown(3);//counts down

		cout << "Hold...7.." << endl;
		countdown(6);

		cout << "Breath out...8.." << endl;
		countdown(7);

	}
}

shared_ptr<vector<string>> getQuotes() {
	fstream file;
	file.open("Quotes.txt", ios::in);
	string str;
	auto quotes = make_shared<vector<string>>();
	if (!file.is_open()) {
		cout << "File failed to open" << endl;
		return 0;
	}
	else {
		while (getline(file, str))
			//cout << str << endl;
			quotes->push_back(str);
		file.close();
	}
	return quotes;

}

void printQuotes(shared_ptr<vector<string>>quotes) {
	srand(time(0));
	int index = rand() % quotes->size();
	cout << quotes->at(index) << endl;
}

UserInfo getUserInfo() {
	UserInfo user;

	user.name = getValidName();//obtaining name
	user.date = getDate();// date
	user.cycle = getCycle();//amount of cycles
	user.before = getMood(); // mood before
	beginBreathing(user);//calling breathing timer
	user.after = getMood(); // mood after breathing

	return user; //returing all object atributes
}




void getSummary(const map<Mood, string>& moodMap, const UserInfo& user) {

	fstream userLog;
	userLog.open("userLogs.dat", ios::in | ios::binary); //opening file in input mode, and ensuring previos work isnt erased

	auto users = make_unique<vector<UserInfo>>();
	unordered_map<Mood, int> moodCounts;
	UserInfo biInfo;

	// i want to use unordered map to see how much times the user felt after the cycle. I want to retrive the data from my bnary file
	if (!userLog.is_open()) {
		cout << "couldnt open file" << endl;
		return;
	}
	else {
		//converts to har to read
		while (userLog.read(reinterpret_cast<char*>(&biInfo), sizeof(UserInfo))) {
			users->push_back(biInfo);// infor that was retrtived will be put in vector
		}
		userLog.close();
	}

	if (users->empty()) {
		cout << "No log data on file.\n";
	}
	else {

		cout << endl << user.name << "'s summary of log history\n";
		for (const auto& user : *users) { // derefrenceing 
			moodCounts[user.before]++; //will get mood(key) and add 1 each iteration of the same mood
		}
		cout << "Before taking a breath:\n";

		for (const auto& pair : moodCounts) {
			cout <<"You felt: " << moodMap.at(pair.first) << " " << pair.second << " time(s)\n";
		}

		moodCounts.clear();

		cout << "After taking a breath:\n";
		for (const auto& user : *users) { // derefrenceing 
			moodCounts[user.after]++; //will get mood(key) and add 1 each iteration of the same mood
		}

		for (const auto& pair : moodCounts) {
			cout << "You felt: " << moodMap.at(pair.first) << " " << pair.second << " time(s)\n";
		}
	

		cout << "Remember you breathe from time to time :)\n";
	}

}

void min() {



	while (true) {
		cin >> *this; // object
		try {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits <streamsize>::max(), '\n');
				throw invalid_argument("Invalid format");
			}
			if (this->numerator == 0 || this->denominator == 0) {
				throw out_of_range("numerator or denominator can not equal 0");
			}
			else {
				this->convertedFraction = static_cast<double>(this->numerator) / this->denominator; // FIX: Cast to double to avoid integer division
				break;
			}
		}
		catch (const invalid_argument& e) {
			cout << e.what() << endl;
		}
		catch (const out_of_range& e) {
			cout << e.what() << endl;
		}
	}
}
}