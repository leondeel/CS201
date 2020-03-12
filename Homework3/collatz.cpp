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
void boxer();

void main() {

	boxer();
}

void boxer() {

	string userContinues = "y";

	while (userContinues[0] == 'y' || userContinues[0] == 'Y') {

		string wordInBox, InputInteger;
		int boxLayers;
		cout << "Type a string you want in the box:  ";
		getline(cin, wordInBox);
		cout << "Type a non-negative integer for the number of layers you want the box to have:  ";
		getline(cin, InputInteger);
		istringstream instream(InputInteger);
		instream >> boxLayers; // Read number from line

		while (!instream || boxLayers < 0) // Error check
		{
			cout << "Please type an INTEGER that is NOT NEGATIVE for the number of layers you want the box to have:  ";
			instream.clear();
			instream.ignore();
			getline(cin, InputInteger);
			istringstream instream(InputInteger);
			instream >> boxLayers; // Read number from line
		}
		cout << endl;
		printBox(wordInBox, boxLayers);
		cout << endl;
		instream.clear();
		instream.ignore();

		cout << "Do you wish to repeat that?  \nIf so, enter \"yes\". Otherwise, enter anything else that doesn't start with the letter \"y\"....   " << endl;
		getline(cin, userContinues);
	}
}
