#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "../include/User.h"
#include "../include/getfunctions.h"

using namespace std;

void beginBreathing(const User& user) {
	system("cls");
	auto quotes = getQuotes();
	printQuotes(quotes);
	timer(user.cycle);
	system("cls");
}