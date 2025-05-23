#include "../include/PremiumUser.h"
#include<iostream>
using namespace std;

void PremiumUser::setCycle() {
	cout << "Cycles with basic getBreath subscrition is up to 10.\n";
	getCycle();
}
void PremiumUser::displayInfo() const {
    User::displayInfo(); // base class's displayInfo
    cout << "User Type: Premium\n";
}