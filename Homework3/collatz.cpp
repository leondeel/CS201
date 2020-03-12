#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::vector;
using std::min_element;
using std::istringstream;

int getUserInt();
bool userWantsToExit();

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

