
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

void printBox(const string& wordInBoxToPrint, const int& boxLayers);
int getUserInt();
void boxer();
bool userWantsToExit();
void collatz();

inline void keepWindowOpen() {
	string tmp;
	cin.clear();
	cout << "Press ENTER to exit the program." << endl;
	getline(cin, tmp);
}

#endif // !_STD_FACILITIES_H_
