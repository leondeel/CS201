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

void main() {
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
		instream >> boxLayers ; // Read number from line
	}
	cout << endl;
	printBox(wordInBox, boxLayers);
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
