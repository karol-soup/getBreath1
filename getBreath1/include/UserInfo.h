#pragma once
#include <string>
#include "Date.h"
#include "Mood.h"

using namespace std;

class UserInfo {
	std::string name;
	Date date;
	short int cycle;
	Mood before;
	Mood after;
public:
	UserInfo() = default;
	

};