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

void printBox(const string& wordInBoxToPrint, const int & starLayers);

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

	printBox(wordInBox, boxLayers);
	boxLayers++;
	printBox(wordInBox, boxLayers);
	boxLayers++;
	printBox(wordInBox, boxLayers);

}
void printBox(const string& wordInBox, const int& starLayers) {
	
	int boxWidth = wordInBox.size() + 2 + 2*starLayers,
		boxHeight = 3 + 2 * starLayers;

	for (int i = 0; i < starLayers; i++) {
		for (int k = 0; k < boxWidth; k++) {
			cout << '*';
		}
		cout << endl;
	}

}



















void inputNames(vector<string> & names) {
	for (int i = 0; i < 10; i++) {
		string name;
		cout << "Please enter a name:  ";
		getline(cin, name);
		names.push_back(name);
	}
}
bool doesNameExist(const string & nameToFind, const vector<string> & names) {
	//This function returns "true" if and only if the name can be found (in any way whatsoever) in the vector of strings.
	// Also note that this search is case-sensitive, because otherwise the code is a little harder to write, and we weren't told whether or not it should be case-sensitive.
	if (nameToFind.size() == 0) return 1; //Any name with zero letters is contained within any list of any kind.
	for (unsigned int i = 0; i < names.size(); i++) {
		for (unsigned int k = 0; nameToFind.size() <= names[i].size() && k <= names[i].size() - nameToFind.size(); k++) {
			for (unsigned int n = 0; names[i][k + n] == nameToFind[n] && n < nameToFind.size(); n++) {
				if (n == nameToFind.size() - 1) return 1;
			}
		}
	}
	return 0;
}
void printNames(const vector<string> & names) {
	for (unsigned int j = 0; j < names.size(); j++) {
		cout << names[j] << endl;
	}
}

//This function sorts its input into dictionary-order, or rather into ASCII order or some equivalent like ASCII or Unicode from least to greatest.
void interesting(vector<string> & names) {
	int vLength = names.size();
	vector<string> names2(vLength);
	for (int i = 0; i < vLength; i++) {
		auto k = min_element(names.begin(), names.end());
		names2[i] = names[distance(names.begin(), k)];
		names.erase(k);
	}
	names = names2;
	printNames(names);
}