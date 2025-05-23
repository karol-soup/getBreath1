#include "../include/Date.h"
#include <iostream>

void Date::setDate() {
	cout << "What is today date? (MM/DD/YYYY)\n";
	cin >> *this;
}
Date Date::getDate() const { return *this; };