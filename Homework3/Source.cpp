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


void printBox(const string& wordInBoxToPrint, const int& boxLayers);
int getUserInt();
void boxer();
bool userWantsToExit();
void collatz();

void main() {

	collatz();
}

//Below lie definitions for my own functions used in this homework, for multiple programs and different parts of the homework.

//This prompts the user for a positive integer, and it makes sure that is what the user actually enters.
int getUserInt() {
	string InputInteger;
	int boxLayers;
	getline(cin, InputInteger);
	istringstream instream(InputInteger);
	instream >> boxLayers; // Read number from line

	while (!instream || boxLayers < 1) // Error check
	{
		cout << "Please type a positive integer only:  ";
		instream.clear();
		instream.ignore();
		getline(cin, InputInteger);
		istringstream instream(InputInteger);
		instream >> boxLayers; // Read number from line
	}
	instream.clear();
	instream.ignore();
	cout << "Thank you" << endl;
	return boxLayers;
}

//This prompts the user to choose between exiting the program or continuing.
bool userWantsToExit() {

	string userExit;
	cout << "\nDo you wish to repeat that?  If so, enter \"yes\". \nOtherwise, if you wish to exit, enter anything else that doesn't start with the letter \"y\"....   " << endl;
	getline(cin, userExit);
	if (userExit[0] == 'Y' || userExit[0] == 'y') {
		return false;
	}
	return true;
}
