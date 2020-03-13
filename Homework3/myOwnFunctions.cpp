#include "std_lib_facilities.h"

//Below lie definitions for my own functions used in this homework and even other homeworks.

int getUserInt() {//This prompts the user for a positive integer and error-checks it.
	string InputInteger;
	int boxLayers;
	getline(cin, InputInteger);
	istringstream instream(InputInteger);
	instream >> boxLayers; // Read number from line

	while (!instream || boxLayers < 1) // Error check
	{
		cout << "Please type a positive integer only:  ";
		instream.clear();
		instream.ignore();
		getline(cin, InputInteger);
		istringstream instream(InputInteger);
		instream >> boxLayers; // Read number from line
	}
	instream.clear();
	instream.ignore();
	cout << "Thank you!" << endl;
	return boxLayers;
}

//This prompts the user to choose between exiting the program or continuing.
bool userWantsToExit() {

	string userExit;
	cout << "\n\nDo you wish to repeat that?  If so, enter \"yes\". \nOtherwise, if you wish to exit, enter anything else that doesn't start with the letter \"y\"....   " << endl;
	getline(cin, userExit);
	if (userExit[0] == 'Y' || userExit[0] == 'y') {
		return false;
	}
	return true;
}
