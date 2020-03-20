

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


inline void keepWindowOpen() {//I have to say that I can't see any bugs in the inline function.
	string tmp;
	cin.clear();
	cout << "Press ENTER to exit the program." << endl;
	getline(cin, tmp);
}

double getDouble() //I copied, pasted, and edited this code from previous homework.  In the future, intend to write a generalized version of this function.
{
	string inputDouble;
	double outputDouble;
	cout << "Enter a temperature in Celsius to convert to Kelvin:  ";
	getline(cin, inputDouble);
	istringstream instream(inputDouble);
	instream >> outputDouble; // Read number from line

	while (!instream || outputDouble < -273.15) // Error check
	{
		cout << "Make sure you enter a NUMBER that is geater than or equal to -273.15" << endl
			<< "It impossible for anything to be colder than -273.15 Celsius. Enter a temperature in Celsius to convert to Kelvin:  ";
		instream.clear();
		instream.ignore();
		getline(cin, inputDouble);
		istringstream instream(inputDouble);
		instream >> outputDouble; // Read number from line
	}
	instream.clear();
	instream.ignore();
	cout << "Thank you!" << endl;
	return outputDouble + 273.15;

}


//Below lie definitions for my own functions used in this homework and even other future homework.
inline  int getUserInt() {//This prompts the user for a positive integer and error-checks it.
	string InputInteger;
	int boxLayers;
	cout << "Please enter a positive integer:  ";
	getline(cin, InputInteger);
	istringstream instream(InputInteger);
	instream >> boxLayers; // Read number from line

	while (!instream || boxLayers < 1) // Error check
	{
		cout << "Please enter a positive integer only:  ";
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
	cout << "\n\nDo you wish to repeat that?  If so, enter \"yes\". \nIf not, enter anything else that doesn't start with the letter \"y\"....   " << endl;
	getline(cin, userExit);
	if (userExit[0] == 'Y' || userExit[0] == 'y') {
		return false;
	}
	return true;
}

#endif // !_STD_FACILITIES_H_

