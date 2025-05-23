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
	//User user;
	//BasicUser user;
	PremiumUser user;
	user.setName();
	user.setDate();
	user.setCycle();
	user.setBeforeMood();
	beginBreathing(user);
	user.getAfterMood();
	return 0;
}

