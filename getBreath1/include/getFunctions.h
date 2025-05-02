#pragma once
#include <string>
#include <map>
#include <vector>
#include <memory>
#include "UserInfo.h"
#include "Mood.h"
#include "Date.h"
using namespace std;

Date getDate();
Mood getMood();
UserInfo getUserInfo();

//functions for testing 
bool isValidMood(short mood);
bool isValidCycle(short cycle);
bool isValidName(const string& name);

string getValidName();
shared_ptr<vector<string>> getQuotes();
void printQuotes(shared_ptr<vector<std::string>>quotes);

void getSummary(const std::map<Mood, std::string>& moodMap, const UserInfo& user);

short int getCycle();
void countdown(const int& num);
void timer(const int& cycles);