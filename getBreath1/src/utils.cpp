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
	timer(user.getCycle());
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


