#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::vector;

void inputNames(vector<string>& names);
bool doesNameExist(const string &nameToFind, const vector<string> &names);
void printNames(const vector<string>& names);

int main() {
	vector<string> names;
	inputNames(names);
	vector<string> names2;
	names2.resize(names.size());
	for (int i = 0; i < names.size(); i++) {
		auto k = std::min_element(names.begin(), names.end());
		int m = distance(names.begin(), k);
		names2[i] = names[m];
		names.erase(k);
	}
	names = names2;
	printNames(names);
	cout << names.size() << endl;
	cout << names2.size() << endl;
	return doesNameExist("Ariel", names);
}
void inputNames(vector<string>& names) {
	for (int i = 0; i < 3; i++) {
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
