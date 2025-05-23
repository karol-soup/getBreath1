#include "../include/PremiumUser.h"
#include<iostream>
using namespace std;

void PremiumUser::displayInfo() const {
    User::displayInfo(); // base class's displayInfo
    cout << "User Type: Premium\n";
}