

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



 
long double getDouble() 
{
	long double outputDouble;
	while (true) // Error check
	{//Inside the loop, istringstream acts weird sometimes.  It will return a double if you just type "enter".
		string inputDouble;
		getline(cin, inputDouble);
		istringstream instream(inputDouble);
		instream >> outputDouble; // Read number from line
		if (instream) break;
	}

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

