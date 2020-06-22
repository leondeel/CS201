#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\my_standard_library.h"

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

//This prompts the user to choose between exiting the program or continuing.
bool userContinues() {

	string userExit;
	cout << "\n\nDo you wish to continue?  If so, enter \'y\'. " << endl
		<< "Otherwise, if you wish to exit, press enter, or enter anything else that doesn't start with the letter \'y\'....   " << endl;
	getline(cin, userExit);
	if (userExit[0] == 'Y' || userExit[0] == 'y') {
		return true;
	}
	return false;
}


long double getDouble()
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
