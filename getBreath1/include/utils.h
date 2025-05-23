#pragma once
#include <string>
#include <map>
#include <vector>
#include <memory>
#include "User.h"
#include "Mood.h"
#include "Date.h"
using namespace std;

shared_ptr<vector<string>> getQuotes();
void printQuotes(shared_ptr<vector<std::string>>quotes);

void timer(const int& cycles);
void countdown(const int& num);
void beginBreathing(const User& user);
//functions for testing 
bool isValidMood(short mood);
bool isValidCycle(short cycle);
bool isValidName(const string& name);