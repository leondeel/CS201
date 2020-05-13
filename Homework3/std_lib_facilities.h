#pragma once

#ifndef _STD_FACILITIES_H_
#define _STD_FACILITIES_H_

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
	string InputInteger;
	int boxLayers;
	cout << "Type a positive integer:  ";
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
inline bool userWantsToExit() {

	string userExit;
	cout << "\n\nDo you wish to repeat that?  If so, enter \"yes\". \nOtherwise, if you wish to exit, enter anything else that doesn't start with the letter \"y\"....   " << endl;
	getline(cin, userExit);
	if (userExit[0] == 'Y' || userExit[0] == 'y') {
		return false;
	}
	return true;
}


double getDouble() //This gets a double from the user and somewhat error-checks it, forcing the user to enter an actual number...most of the time.
//This istringstream has bugs.  Calling instream.clear() doesn't do enough to reset everything back from scratch.  
//I looked over forums, but to no avail.  I blame the makers of istringstream.  Or am I missing something?
//I could make my own version of this code COMPLETELY from scratch without even using istringstream, but that would be a whole extra assigment in itself.
{
	string inputDouble;
	long double outputDouble;
	getline(cin, inputDouble);
	istringstream instream(inputDouble);
	instream >> outputDouble; // Read number from line
	cout << outputDouble << endl;

	while (!instream) // Error check
	{//Inside the loop, istringstream acts weird sometimes.  It will return a double if you just type "enter".
		cout << "Make sure you enter a NUMBER:  ";
		cin.clear();
		instream.clear();
		getline(cin, inputDouble);
		istringstream instream(inputDouble);
		instream >> outputDouble; // Read number from line again to repeat process.
		cout << outputDouble << endl;
	}
	instream.clear();
	cin.clear();
	cout << "Thank you!  You entered " << outputDouble << endl;
	return outputDouble;

}

#endif // _STD_FACILITIES_H_
