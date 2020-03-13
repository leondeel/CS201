#include "std_lib_facilities.h"


void main() {

	int k;
	do {
		cout << "Hello!" << endl;
		k = getUserInt();
		cout << "You entered " << k << '.' << endl;
	} while (!userWantsToExit);


	keepWindowOpen();
}