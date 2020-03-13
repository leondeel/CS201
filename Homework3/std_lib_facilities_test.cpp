#include "std_lib_facilities.h"

void test() {

	int k;
	do {
		k = getUserInt();
	} while (!userWantsToExit);


	keepWindowOpen();
}