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

int main() {
	vector<string> names;
	inputNames(names);
	return doesNameExist("Ariel", names);
}


bool doesNameExist(const string& nameToFind, const vector<string>& names) {
	for (int i = 0; i <= names.size(); i++) {
		for (int k = 0; k <= names[i].size(); k++) {
			for (int n = 0; n <= nameToFind.size(); n++) {
				if (nameToFind[n] = names[i][k])
			}
		}
	}
	return 0;
}

void inputNames(vector<string> &names) {
	for (int i = 0; i < 10; i++) {
		string name;
		cout << "Please enter a name:  ";
		getline(cin, name);
		names.push_back(name);
	}
}
