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

	if (nameToFind.size() == 0) return 1; //Any name with zero letters is contained within any list of any kind.
	for (unsigned int i = 0; i < names.size(); i++) {
		for (unsigned int k = 0; k <= names[i].size() - nameToFind.size() && 0<= names[i].size() - nameToFind.size(); k++) {
			for (unsigned int n = 0; names[i][k + n] == nameToFind[n] && n < nameToFind.size(); n++ ) {
				if (n == nameToFind.size() - 1) return 1;			
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
