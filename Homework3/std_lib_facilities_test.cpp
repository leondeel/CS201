#include "std_lib_facilities.h"

void test() {

	int k;
	do {
		k = getUserInt();
		cout << "You entered " << k <<'.'<< endl;
	} while (!userWantsToExit);


	keepWindowOpen();
}