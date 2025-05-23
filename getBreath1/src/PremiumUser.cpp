#include "../include/PremiumUser.h"
#include "../include/Utils.h"
#include<iostream>
using namespace std;

void PremiumUser::setCycle() {
	cout << "Cycles with basic getBreath subscrition is up to 5.\n";
	getCycle();
}
void PremiumUser::displayInfo() const {
    User::displayInfo(); // base class's displayInfo
    cout << "User Type: Premium\n";
}