#include "../include/BasicUser.h"
#include<iostream>
using namespace std;

void BasicUser::displayInfo() const {
    User::displayInfo(); // base class's displayInfo
    cout << "User Type: Basic\n";
}