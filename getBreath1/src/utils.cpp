#include "../include/Date.h"
#include "../include/Mood.h"
#include "../include/User.h"
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

void getSummary(const map<Mood, string>& moodMap, const User& user) {

	fstream userLog;
	userLog.open("userLogs.dat", ios::in | ios::binary); //opening file in input mode, and ensuring previos work isnt erased

	auto users = make_unique<vector<User>>();
	unordered_map<Mood, int> moodCounts;
	User biInfo;

	// i want to use unordered map to see how much times the user felt after the cycle. I want to retrive the data from my bnary file
	if (!userLog.is_open()) {
		cout << "couldnt open file" << endl;
		return;
	}
	else {
		//converts to har to read
		while (userLog.read(reinterpret_cast<char*>(&biInfo), sizeof(User))) {
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

void logUser(User& user) {
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

void countdown(const int& num) {
	this_thread::sleep_for(1s);// pause for 1 sec
	for (int i = num; i >= 1;i--) {
		cout << i << endl;
		this_thread::sleep_for(1s);//pause for 1 sec
	}
}
void beginBreathing(const User& user) {
	system("cls");
	auto quotes = getQuotes();
	printQuotes(quotes);
	timer(user.cycleCount);
	system("cls");
}
//in order to test
bool isValidMood(short mood) {
	return mood <= 5 && mood >= 1;
}
bool isValidCycle(short cycle) {
	return cycle >= 1 && cycle <= 15;
}
bool isValidName(const string& name) {
	return !name.empty() && name.length() <= 35;
}


