#include "../include/UserInfo.h"
#include <iostream>
#include <fstream>
using namespace std;

void logUser(UserInfo& user) {
	fstream userLog; //creating file
	userLog.open("userLogs.dat", ios::out | ios::app | ios::binary); //opening file in input mode, and ensuring previos work isnt erased


	if (!userLog.is_open()) {

		cout << "Couldnt open file" << endl;
	}
	else {
		userLog.write(reinterpret_cast<char*>(&user), sizeof(UserInfo));//writing in info about user

		userLog.close();

	}
}