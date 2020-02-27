#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

int main(int argc, char** argv) {

	std::vector<std::string> names;
	for (int i = 0; i < 10; i++) {

		std::string name;
		std::cout << "Please enter a name:  ";
		std::getline(cin, name);
		names.push_back(name);
	}
	return 0;
}	
