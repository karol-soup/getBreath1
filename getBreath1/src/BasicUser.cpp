#include "../include/BasicUser.h"
#include "../include/Utils.h"
#include<iostream>
using namespace std;

void BasicUser::setCycle() {
	cout << "Cycles with basic getBreath subscrition is 2.\n";
	cycleCount = 2;
}
void BasicUser::displayInfo() const {
    User::displayInfo(); // base class's displayInfo
    cout << "User Type: Basic\n";
}