#include "../include/BasicUser.h"
#include "../include/Utils.h"
#include<iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <ctime>
#include <stdexcept>
#include <map>
#include <unordered_map>
using namespace std;

void BasicUser::setCycle() {
	cout << "Cycles with basic getBreath subscrition is 2.\n";
	cycleCount = 2;
}
void BasicUser::displayInfo() const {
    User::displayInfo(); // base class's displayInfo
    cout << "User Type: Basic\n";
}
void BasicUser::getSummary() const {
	fstream userLog("userLogs.dat", ios::in | ios::binary);//opening file in input mode, and ensuring previos work isnt erased
	if (!userLog) {
		cout << "Couldn't open file.\n";
	}
	else {
		unordered_map<Mood, int> moodCounts;
		auto users = make_unique<std::vector<BasicUser>>();
		BasicUser user;
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
				moodCounts[user.getAfterMood()]++; //will get mood(key) and add 1 each iteration of the same mood
			}
			for (const auto& pair : moodCounts) {

				cout << "You felt: " << moodMap.at(pair.first) << " " << pair.second << " time(s)\n";

			}
			moodCounts.clear();
			cout << "After taking a breath:\n";
			for (const auto& user : *users) { // derefrenceing 
				moodCounts[user.getBeforeMood()]++; //will get mood(key) and add 1 each iteration of the same mood
			}
			for (const auto& pair : moodCounts) {
				cout << "You felt: " << moodMap.at(pair.first) << " " << pair.second << " time(s)\n";
			}
			cout << "Remember you breathe from time to time :)\n";
		}
	}
}