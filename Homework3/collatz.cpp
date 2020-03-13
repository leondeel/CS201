#include "std_lib_facilities.h"

void collatz() {
	int k;

	do {
		cout << "Type a positive integer:  ";
		k = getUserInt();
		cout << endl << k << ", ";
		while (k != 1) {
			if (k % 2) {
				k = 3 * k + 1;
				cout << k << ", ";
			}
			else {
				k = k / 2;
				cout << k << ", ";
			}
		}
	} while (!userWantsToExit());
}

