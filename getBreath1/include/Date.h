#pragma once
#include <iostream>
#include<string>
#include<sstream>// for istringstring input

using namespace std;
class Date {
	short int month;
	short int day;
	short int year;
public:
	Date()=default;//default constructor

    friend inline std::istream& operator>>(std::istream& input, Date& date) {
        char slash1, slash2; // Need two slash variables
        while (true) {
            // Read as string first to handle invalid non-numeric input gracefully
            string date_str;
            input >> date_str; // Read the whole line/token

            // Attempt to parse from string
            istringstream iss(date_str); // Use istringstream for parsing
            iss >> date.month >> slash1 >> date.day >> slash2 >> date.year;

            if (iss.fail() || slash1 != '/' || slash2 != '/') {
                std::cout << "Invalid date format. Please use MM/DD/YYYY.\n";
                // Clear the main input stream in case of residual invalid input
                input.clear();
                input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (date.month < 1 || date.month > 12) { // Month 1-12
                std::cout << "Month must be between 1-12. Please try again.\n";
            }
            else if (date.day < 1 || date.day > 31) { // Day 1-31 (simplified, real date validation is complex)
                std::cout << "Day must be between 1-31. Please try again.\n";
            }
            else if (date.year < 2000 || date.year > 3000) {
                std::cout << "Year must be between 2000-3000. Please try again.\n";
            }
            // Basic check for valid days in specific months (e.g., Feb 29, April 30)
            else if ((date.month == 2 && date.day > 29) || // Feb
                ((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) && date.day > 30)) { // April, June, Sep, Nov
                std::cout << "Invalid day for the specified month. Please try again.\n";
            }
            else {
                break; // All checks passed
            }
            // If any check fails, the loop continues and prompts for input again.
        }
        return input;
    }

    friend inline std::ostream& operator<<(std::ostream& output, const Date& date) { // Added const
        char slash = '/';
        output << date.month << slash << date.day << slash << date.year;
        return output;
    }

	void setDate();
	Date getDate()const;

	~Date() {};
};