// Coded by M. Ariel Hernandez for Computer Science 201, June 2020

#include "../my_standard_library.h"

//Below lie definitions for my own functions used in this homework and even other future homework.

unsigned int getPosInt() {//This prompts the user for a positive integer and error-checks it.
		
	unsigned int boxLayers;
	string InputInteger;

	while (true) // Error check
	{
		cout << "Please type a positive integer only:  ";
		getline(cin, InputInteger);
		istringstream instream(InputInteger);
		instream >> boxLayers; // Read number from line
		if (instream && boxLayers > 0) break;
	}
	return boxLayers;
}
bool userYesNo() {  //Prompts the user to answer yes or no.
	string userExit;
	getline(cin, userExit);
	if (userExit[0] == 'Y' || userExit[0] == 'y') {
		return true;
	}
	return false;
}

//This prompts the user to choose between exiting the program or continuing.
bool userContinues() {

	cout << "Do you wish to continue?  If so, enter \"y\". " << endl
		<< "Otherwise, press enter, or enter anything else that doesn't start with the letter \"y\"....   " << endl;
	return userYesNo();
}


long double getDouble()  //this function prompts user for long double, error checks it, and returns it.
{
	long double outputDouble;
	string inputDouble;
	while (true) // Error check
	{
		cout << "Please correctly enter a double." << endl;
		getline(cin, inputDouble);
		istringstream instream(inputDouble);
		instream >> outputDouble; // Read number from line
		if (instream) break;
	}

	cout << "Thank you!  You entered " << outputDouble << endl;
	return outputDouble;

}
