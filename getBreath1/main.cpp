

#include <iostream>

#include "include/Date.h"
#include "include/Mood.h"
#include "include/UserInfo.h"
#include "include/beginBreathing.h"
#include "include/getFunctions.h"
#include "include/logUser.h"
#include <map>

using namespace std;


int main()
{
	map<Mood, string> moodMap{
		{Sad, "Sad"},
		{Frustrated, "Frustrated"},
		{Neutral, "Neutral"},
		{Happy, "Happy"},
		{Calm, "Calm"}
	};

	UserInfo user;

	user = getUserInfo();

	logUser(user);

	getSummary(moodMap, user);
	
	return 0;
}

