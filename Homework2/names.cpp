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

void inputNames(vector<string>& names);
bool doesNameExist(const string &nameToFind, const vector<string> &names);
void printNames(const vector<string>& names);
void interesting(vector<string>& names);
//This function sorts its input into dictionary-order, or rather into ASCII order or some equivalent like ASCII or Unicode from least to greatest.

int main() {
	vector<string> names;
	inputNames(names);
	interesting(names);

	vector<int> coins(5);
	const vector<string> coinTypes = { "pennies", "nickles", "dimes", "quaters", "half-dollars" };
	string line;

	for (int i = 0; i < 5; i++) {
		cout << "How many " << coinTypes[i] << " do you have?" << endl;
		getline(cin, line);
		istringstream instream(line);
		instream >> coins[i]; // Read number from line
		while (!instream) // Error check
		{
			cout << "Please type an INTEGER for the number of " << coinTypes[i] << " you have.  It can be negative if you want." << endl
				<< "How many " << coinTypes[i] << " do you have?" << endl;
			getline(cin, line);
			istringstream instream(line);
			instream >> coins[i]; // Read number from line
		}
	}
	for (int i = 0; i < 5; i++) {
		cout << "You have " << coins[i] << ' ' << coinTypes[i] << '.' << endl;
	}
	cout << "The value of all your coins is "
		<< coins[0] + coins[1] * 5 + coins[2] * 10 + coins[3] * 25 + coins[4] * 50 << " cents." << endl;

	return doesNameExist("Ariel", names);
}
void inputNames(vector<string>& names) {
	for (int i = 0; i < 10; i++) {
		string name;
		cout << "Please enter a name:  ";
		getline(cin, name);
		names.push_back(name);
	}
}
bool doesNameExist(const string& nameToFind, const vector<string>& names) {
	//This function returns "true" if and only if the name can be found (in any way whatsoever) in the vector of strings.
	// Also note that this search is case-sensitive, because otherwise the code is a little harder to write, and we whether or not it should be case-sensitive.
	if (nameToFind.size() == 0) return 1; //Any name with zero letters is contained within any list of any kind.
	for (unsigned int i = 0; i < names.size(); i++) {
		for (unsigned int k = 0; nameToFind.size() <= names[i].size() && k <= names[i].size() - nameToFind.size(); k++) {
			for (unsigned int n = 0; names[i][k+n] == nameToFind[n] && n < nameToFind.size(); n++ ) {
				if (n == nameToFind.size() - 1) return 1;			
			}
		}
	}
	return 0;
}
void printNames(const vector<string>& names) {
	for (unsigned int j = 0; j < names.size(); j++) {
		cout << names[j] << endl;
	}
}

//This function sorts its input into dictionary-order, or rather into ASCII order or some equivalent like ASCII or Unicode from least to greatest.
void interesting(vector<string>& names) {
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
