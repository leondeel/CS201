

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




double getDouble() //This gets a double from the user and somewhat error-checks it, forcing the user to enter an actual number...most of the time.
//This istringstream has bugs.  Calling instream.clear() doesn't do enough to reset everything back from scratch.  
//I looked over forums, but to no avail.  I blame the makers of istringstream.
//I could make my own version of this code COMPLETELY from scratch without even using istringstream, but that would be a whole extra assigment in itself.
{
	string inputDouble;
	double outputDouble;
	getline(cin, inputDouble);
	istringstream instream(inputDouble);
	instream >> outputDouble; // Read number from line

	while (!instream ) // Error check
	{//Inside the loop, istringstream acts weird sometimes.  It will return a double if you just type "enter".
		cout << "Make sure you enter a NUMBER:  ";
		instream.clear();
		instream.ignore();
		getline(cin, inputDouble);
		istringstream instream(inputDouble);
		instream >> outputDouble; // Read number from line again to repeat process.
	}
	instream.clear();
	instream.ignore();
	cout << "Thank you!  You entered " << outputDouble << endl;
	return outputDouble;

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

