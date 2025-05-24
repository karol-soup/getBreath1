#include "../include/PremiumUser.h"
#include "../include/Utils.h"
#include<iostream>
using namespace std;

void PremiumUser::setCycle() {
	cout << "Cycles with Premium getBreath subscrition is up to 5.\n";
	User::setCycle();// have to clarify or else will call itself
	cycleCount = getCycle();
}
void PremiumUser::displayInfo() const {
    User::displayInfo(); // base class's displayInfo
    cout << "User Type: Premium\n";
}