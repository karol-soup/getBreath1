#pragma once  
#include <string>  
#include <map>  
#include <vector>  
#include <memory>  
#include "User.h"   
#include "Date.h" 
using namespace std;  

shared_ptr<vector<string>> getQuotes();  
void printQuotes(shared_ptr<vector<std::string>> quotes);  

void countdown(const int& num);
void timer(const int& cycles);  
void beginBreathing(const User& user); // Ensure User is properly included and defined.  

//functions for testing   
bool isValidMood(short mood);  
bool isValidCycle(short cycle);  
bool isValidName(const string& name);