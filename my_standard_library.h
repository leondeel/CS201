#pragma once


#ifndef _MY_STANDARD_LIBRARY_
#define _MY_STANDARD_LIBRARY_

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::vector;
using std::min_element;
using std::istringstream;


//Below lie definitions for my own functions used in this homework and even other future homework.

inline int getUserInt() {//This prompts the user for a positive integer and error-checks it.

	int boxLayers;
	while (true) // Error check
	{
		cout << "Please type a positive integer only:  ";
		string InputInteger;
		getline(cin, InputInteger);
		istringstream instream(InputInteger);
		instream >> boxLayers; // Read number from line
		if (instream || boxLayers > 0) break;
	}
	return boxLayers;
}

//This prompts the user to choose between exiting the program or continuing.
inline bool userWantsToExit() {

	string userExit;
	cout << "\n\nDo you wish to repeat that?  If so, enter \"yes\". \nOtherwise, if you wish to exit, enter anything else that doesn't start with the letter \"y\"....   " << endl;
	getline(cin, userExit);
	if (userExit[0] == 'Y' || userExit[0] == 'y') {
		return false;
	}
	return true;
}


inline long double getDouble() 
{
	long double outputDouble;
	while (true) // Error check
	{
		cout << "Please correctly enter a double." << endl;
		string inputDouble;
		getline(cin, inputDouble);
		istringstream instream(inputDouble);
		instream >> outputDouble; // Read number from line
		if (instream) break;
	}

	cout << "Thank you!  You entered " << outputDouble << endl;
	return outputDouble;

}

#endif // _MY_STANDARD_LIBRARY_