#include "../include/utils.h"
#include "../include/Mood.h"

Mood getMood() {
	short int mood;
	cout << "Using our scale 1-5, how are you feeling at the moment?\n"
		<< "(1 - Sad, 2 - Frustrated, 3 - Neutral, 4 - Happy, 5 - Calm)\n";
	while (true) {
		cin >> mood;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please try again.\n";
		}
		else if (!isValidMood(mood)) {
			cout << "Input must be between 1-5. Please try again.\n";
		}
		else break;
	}

	return static_cast <Mood>(mood);
}