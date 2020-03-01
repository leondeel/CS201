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


void InputNames(vector<string>& names);


int main(int argc, char** argv) {

	vector<string> names;

	InputNames(names);

	for (int i = 0; i < 10; i++) {
		cout << names[i] << endl;
	}
	return 0;
}


void InputNames(vector<string> &names) {

	for (int i = 0; i < 10; i++) {

		string name;
		cout << "Please enter a name:  ";
		getline(cin, name);
		names.push_back(name);
	}
}
