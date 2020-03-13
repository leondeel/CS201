#include "std_lib_facilities.h"


void main() {

	do {
		string wordInBox;
		cout << "Type a string you want in the box:  ";
		getline(cin, wordInBox);
		cout << "Type a positive integer for the number of layers you want the box to have:  ";
		int boxLayers = getUserInt(); //This outputs a positive integer from the user and error-checks it.
		cout << endl;
		printBox(wordInBox, boxLayers);//This prints the box.
		cout << endl;

	} while (!userWantsToExit());  //This prompts the user to choose whether to quit the program or continue.
}

void printBox(const string& wordInBox, const int& boxLayers) {

	int boxWidth = wordInBox.size() + 2 + 2 * boxLayers,
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
	cout << endl;

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
