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


void printBox(const string& wordInBoxToPrint, const int & boxLayers);
int getUserInt();
void boxer();
bool userWantsToExit();

void main() { 
	
	boxer();
	while (!userWantsToExit()) {
		boxer();
	}
}



void boxer() {
		string wordInBox;
		cout << "Type a string you want in the box:  ";
		getline(cin, wordInBox);
		cout << "Type a non-negative integer for the number of layers you want the box to have:  ";
		int boxLayers = getUserInt(); //This gets a positive integer from the user.
		cout << endl;
		printBox(wordInBox, boxLayers);
		cout << endl;
}

void printBox(const string& wordInBox, const int& boxLayers) {
	
	int boxWidth = wordInBox.size() + 2 + 2*boxLayers,
		boxHeight = 3 + 2 * boxLayers;

	for (int i = 0; i < boxLayers; i++) {
		for (int k = 0; k < boxWidth; k++) {
			cout << '*';
		}
		cout << endl;
	}
	for (int i = 0; i < boxLayers; i++) cout << '*';
	for (int i = 0; i < boxWidth - 2 * boxLayers; i++) cout << ' ';
	for (int i = 0; i < boxLayers; i++) cout << '*';
	cout<< endl;

	for (int i = 0; i < boxLayers; i++) cout << '*';
	cout << ' ' << wordInBox << ' ';
	for (int i = 0; i < boxLayers; i++) cout << '*';
	cout << endl;

	for (int i = 0; i < boxLayers; i++) cout << '*';
	for (int i = 0; i < boxWidth - 2 * boxLayers; i++) cout << ' ';
	for (int i = 0; i < boxLayers; i++) cout << '*';
	cout << endl;

	for (int i = 0; i < boxLayers; i++) {
		for (int k = 0; k < boxWidth; k++) {
			cout << '*';
		}
		cout << endl;
	}
}

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

bool userWantsToExit() {
	cin.clear();
	cin.ignore();
	string userExit;
	cout << "Do you wish to repeat that?  \nIf so, enter \"yes\". Otherwise, enter anything else that doesn't start with the letter \"y\"....   " << endl;
	getline(cin, userExit);
	if (userExit[0] != 'Y' || userExit[0] != 'y') return 0;
	else return 1;
}