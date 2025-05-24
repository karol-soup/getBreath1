#include "../include/Date.h"
#include "../include/User.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <ctime>
#include <stdexcept>
#include <map>
#include <unordered_map>
#include <cstdlib>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono_literals;

shared_ptr<vector<string>> getQuotes() {
	fstream file;
	file.open("C:\\Users\\Karol Suarez\\Desktop\\getBreath1\\getBreath1\\Quotes.txt", ios::in);
	string str;
	auto quotes = make_shared<vector<string>>();
	if (!file.is_open()) {
		cout << "File failed to open" << endl;
		return nullptr;
	}
	else {
		while (getline(file, str)) {
			//cout << str << endl;
			quotes->push_back(str);
		}
		file.close();
	}
	return quotes;

}
void printQuotes(shared_ptr<vector<string>>quotes) {
	srand(time(0));
	int index = rand() % quotes->size();
	cout << quotes->at(index) << endl;
}
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
void beginBreathing(const User& user) {
	system("cls");
	auto quotes = getQuotes();
	if (quotes == nullptr) {
		cout << "Error: Could not load quotes.";
			return;
	}
	printQuotes(quotes);
	timer(user.getCycle());
	system("cls");
}
//in order to test
bool isValidMood(short mood) {
	if (mood <= 5 && mood >= 1)
		return true;
	else
		throw out_of_range("Cycles entered must be between 1-5. \n");
}
bool isValidCycle(short cycle) {
	if (cycle >= 1 && cycle <= 15)
		return true;
	else
		throw out_of_range("Cycles entered must be between 1-15. \n");
}
bool isValidName(const string& name) {
	if (!name.empty() && name.length() <= 35)
		return true;
	else
		throw invalid_argument("Name is excessivly long. No more than 35 character. Please try again.\n");
}


