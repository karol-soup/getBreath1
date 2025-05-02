#pragma once
#include <string>
#include "Date.h"
#include "Mood.h"

struct UserInfo {
	std::string name;
	Date date;
	short int cycle;
	Mood before;
	Mood after;
};