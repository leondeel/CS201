#include "std_lib_facilities.h"

void main() {
	int k;

	do {
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

