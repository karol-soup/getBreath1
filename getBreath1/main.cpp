#include <iostream>
#include "include/Date.h"
#include "include/User.h"
#include "include/BasicUser.h"
#include "include/PremiumUser.h"
#include "include/utils.h"
#include <map>

using namespace std;


int main()
{

	PremiumUser user;
	user.setName();
	user.setDate();
	user.setBeforeMood();
	user.setCycle();
	beginBreathing(user);
	user.setAfterMood();
	user.displayInfo();
	//user.logToFile(user);
	//user.getSummary();
	return 0;
}

